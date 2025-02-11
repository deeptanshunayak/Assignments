#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void sendFile(FILE *fp, int sockfd) {
    char buffer[BUFFER_SIZE];
    
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFFER_SIZE);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *filename = "received_file.txt";
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("172.30.30.184");

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Sending file...\n");
    sendFile(fp, sockfd);
    printf("File sent successfully.\n");

    fclose(fp);
    close(sockfd);
    
    return 0;
}

