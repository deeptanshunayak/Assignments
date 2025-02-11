#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
    int server_fd, new_socket, client_socket[MAX_CLIENTS], max_sd=0, activity, sd;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[1024];
    int i = 0;
    fd_set readfds; // Set of socket descriptors

    // Initialize client sockets to 0 (empty)
    for (i = 0; i < MAX_CLIENTS; i++)
        client_socket[i] = 0;

    // 1. Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Bind socket to IP/Port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // 3. Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Clear the socket set
        FD_ZERO(&readfds);

        // Add server socket to set
        FD_SET(server_fd, &readfds);
        max_sd = server_fd;

        // Add client sockets to set
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];
            if (sd > 0) FD_SET(sd, &readfds);
            if (sd > max_sd) max_sd = sd;
        }

        // 4. Wait for activity on any socket
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select error");
            continue;
        }

        // 5. Check for new connections
        if (FD_ISSET(server_fd, &readfds)) {
            new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
            if (new_socket < 0) {
                perror("Accept failed");
                continue;
            }

            printf("New connection: socket %d, IP: %s, Port: %d\n",
                   new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            // Add new socket to client array
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    break;
                }
            }
        }

        // 6. Handle data from clients
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];

            if (FD_ISSET(sd, &readfds)) {
                int bytes_read = read(sd, buffer, sizeof(buffer));
                if (bytes_read == 0) {
                    // Client disconnected
                    printf("Client on socket %d disconnected.\n", sd);
                    close(sd);
                    client_socket[i] = 0;
                } else {
                    buffer[bytes_read] = '\0';
                    printf("Client %d: %s\n", sd, buffer);
                    send(sd, "Message received", 17, 0);
                }
            }
        }
    }

    return 0;
}

