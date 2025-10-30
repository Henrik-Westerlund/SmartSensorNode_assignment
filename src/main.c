#include <stdio.h>

#include "TCP/TCPClient.h"
#include "HTTP/HTTPClient.h"

int main()
{
    char* data = "{\r\n\t\"devide\": \"UUID\",\r\n\t\"time\": \"2025-10-30\"\r\n\t\"temperature\": \"19°C\"\r\n}";

    tcp_client(data, http_post);


    return 0;
}