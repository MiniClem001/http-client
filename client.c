#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>

#define PORT 8080
#define IP_ADDR "127.0.0.1"
#define BUFF_SIZE 1024

int main(void)
{
    // creating the socket
    int sockfd = socket(PF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("Error creating the socket!");
        exit(EXIT_FAILURE);
    }

    // defining the address and port
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP_ADDR, &address.sin_addr) != 1)
    {
        perror("IP Address invalid!");
        exit(EXIT_FAILURE);
    }

    // connecting to the socket
    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Connection error!");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", IP_ADDR, PORT);

    char mess[] = "GET / HTTP/1.1\r\nHost: 127.0.0.1:8080\r\nConnection: close\r\n\r\n";
    char buff[BUFF_SIZE] = {0};

    if (send(sockfd, mess, strlen(mess), 0) == -1)
    {
        perror("Error sending the message!");
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_received;
    while ((bytes_received = recv(sockfd, buff, sizeof(buff) - 1, 0)) > 0)
    {
        // null terminate the received data
        buff[bytes_received] = '\0';

        // print the received data
        printf("%s", buff);

        // clear the buffer for next read
        memset(buff, 0, sizeof(buff));
    }

    if (bytes_received == -1)
    {
        perror("Error receiving the message!");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    exit(EXIT_SUCCESS);
}