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

int main(void)
{
    // creating the socket
    int sockfd = socket(PF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Error creating the socker!\n");
        exit(EXIT_FAILURE);
    }

    // defining the address and port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP_ADDR, &address.sin_addr) != 1)
    {
        printf("IP Address invalid!\n");
        exit(EXIT_FAILURE);
    }

    // connecting to the socket
    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", IP_ADDR, PORT);

    close(sockfd);

    exit(EXIT_SUCCESS);
}