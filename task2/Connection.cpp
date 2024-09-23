#include "Comms.h"
#include "Connection.h"

#include <sys/socket.h>


#include <iostream>
#include <unistd.h>
#include <vector>

int Connection::MAX_SIZE_OF_BUFFER = 512;
struct timeval Connection::TIMEOUT = {.tv_sec = 0};

Connection::Connection(int sock) : sock(sock) {}

Connection::~Connection() {
    close(this->sock);
}

void Connection::sendMessage(const std::string& message) {
    int bytesSent = send(this->sock, message.c_str(), message.size(), 0);
    if (bytesSent == -1) {
        std::cerr << "[ERROR] - error whilst sending message" << std::endl;
    }
}

std::string Connection::receiveMessage() {
    std::vector<char> buffer(MAX_SIZE_OF_BUFFER);
    int bytesReceived = recv(this->sock, buffer.data(), buffer.size(), 0);

    if (bytesReceived > 0) {
        return std::string(buffer.data(), static_cast<std::string::size_type>(bytesReceived));
    } else {
        std::cerr << "Error whilst receiving message or connection has closed" << std::endl;
        return "";
    }
}
