#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];

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

    printf("Connected to server! Type your message:\n");

    while (1) {
        printf("You: ");
        fgets(buffer, 1024, stdin);
        send(sock, buffer, strlen(buffer), 0);
        recv(sock, buffer, 1024, 0);
        printf("Server: %s\n", buffer);
    }

    close(sock);
    return 0;
}

