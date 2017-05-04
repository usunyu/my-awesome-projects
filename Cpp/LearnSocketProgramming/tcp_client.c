#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {

    // create a socket
    int network_socket;
    network_socket = socket(AF_INT, SOCK_STREAM, 0);

    return 0;
}