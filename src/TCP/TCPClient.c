#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "TCPClient.h"

/* Skicka in en funktionspekare till en funktion som ligger i HTTPClient.c som bygger ihop en request kanske? */
/* httpbin.org:     18.207.14.107 
                    44.205.165.147
                    3.227.143.56
                    52.72.129.198
*/
int tcp_client()
{
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    /* char* message = "POST /HTTP_Methods/post_post HTTP/1.1\r\nHost: httpbin.org\r\n\r\n"; */
    char* message = "GET / HTTP/1.1\r\nHost: httpbin.org\r\n\r\n";
    
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
    printf("Server: %s\n", buffer);

    close(sock);

    return 0;
}