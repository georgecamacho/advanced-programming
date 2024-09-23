#include "Comms.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>

Comms::Comms(const char* address, int port) {
    this->sockFD = socket(AF_INET, SOCK_STREAM, 0);

    if (this->sockFD == SOCKET_ERROR) { std::cout << "Error when creating socket!" << std::endl;}

    this->address.sin_family = AF_INET;
    this->address.sin_port = htons(port);
    this->address.sin_addr.s_addr = inet_addr(address);
}
