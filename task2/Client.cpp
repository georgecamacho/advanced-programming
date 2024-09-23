#include "Client.h"

#include <unistd.h>
#include <iostream>

#include "SockException.h"

using namespace std;

Client::Client(const char* address, int port):Comms(address, port) {
    int responseCode = connect(this->sockFD, (sockaddr*) &this->address, sizeof(this->address));

    if (responseCode == SOCKET_ERROR) { 
        throw SockException("[ERROR] - error with connection", errno);
    }
    cout << "Client: Connected to server successfully!" << endl;

}

Client::~Client() {
    cout << "Client: Connection closed." << endl;
    close(this->sockFD);
}
