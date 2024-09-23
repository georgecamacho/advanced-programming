#include "Server.h"

#include <iostream>
#include <unistd.h>

#include "Connect.h"

Server::Server(const char* address, int port): Comms(address, port) {
    int responseCode = bind(this->sockFD, (sockaddr*) &this->address, sizeof(this->address));
    // "std::" added here as the library contains a bind function, which conflicts the line above
    if (responseCode == SOCKET_ERROR) { 
        std::cout << "[ERROR] - error whist binding" << strerror(errno) << std::endl; 
    } else {
        std::cout << "Server: Bound to address and port successfully!" << std::endl;
    }


}

Server::~Server(){
    close(this->sockFD);
    std::cout << "Server: Connection closed successfully!" << std::endl;
}


void Server::start(){
    int responseCode = listen(this->sockFD, 1);

    if (responseCode == SOCKET_ERROR) { 
        std::cout << "[ERROR] - error whilst listening" << std::endl; 
    } else {
        std::cout << "The server has successfully started! Listening for connections..." << std::endl;
    }


    int inboundConnection = accept(this->sockFD, NULL, NULL);
    if (inboundConnection != SOCKET_ERROR) {
        std::cout << "Server: Client connection has been received! Successfully connected!" << std::endl;
    } else {
        std::cout << "Server: Connection established with client successfully!" << std::endl;
        close(inboundConnection);
    }
}
