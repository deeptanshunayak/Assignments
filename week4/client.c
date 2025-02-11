#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // 1. Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "172.30.30.145", &server_addr.sin_addr);

    // 3. Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // 4. Send data to server
    char *message = "Hello, Server!";
    send(sock, message, strlen(message), 0);

    // 5. Read response from server
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s\n", buffer);

    // 6. Close socket
    close(sock);
    return 0;
}

