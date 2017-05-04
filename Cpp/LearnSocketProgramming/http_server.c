#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

int main() {

    FILE *html_data;
    html_data = fopen("index.html", "r");

    char response_data[1024];
    fgets(response_data, 1024, html_data);

    return 0;
}