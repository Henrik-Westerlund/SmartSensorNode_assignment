#include <stdio.h>
#include <string.h>

#include "HTTPClient.h"

char* http_post(char* _Body)
{
    char* post_headers = "POST /post HTTP/1.1\r\nHost: httpbin.org\r\n\r\n";

    return strcat(post_headers, _Body);
}