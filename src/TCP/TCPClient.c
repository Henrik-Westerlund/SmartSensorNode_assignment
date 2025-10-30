#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "TCPClient.h"

int tcp_client(char* _Data, char* (*http_request)(char*))
{
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    char* message = http_request(_Data);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Failed to assign socket\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    if (inet_pton(AF_INET, "18.207.14.107", &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection failed\n");
        return -1;
    }

    send(sock, message, strlen(message), 0);

    read(sock, buffer, sizeof(buffer));

    close(sock);

    return 0;
}