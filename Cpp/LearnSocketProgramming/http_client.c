#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {

    char *address;
    address = argv[1];

    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // connect to an address
    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(80);
    inet_aton(address, &remote_address.sin_addr.s_addr);

    connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));

    return 0;
}