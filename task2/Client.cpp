#include "Client.h"

#include <iostream>
#include <thread>
#include <unistd.h>

#include "SockException.h"

using namespace std;

Client::Client(const char* address, int port):Comms(address, port) {
    int responseCode = connect(this->sockFD, (sockaddr*) &this->address, sizeof(this->address));

    if (responseCode == SOCKET_ERROR) { 
        throw SockException("[ERROR] - error with connection", errno);
    }
    connection = new Connection(this->sockFD);
    cout << "Client: Connected to server successfully!" << endl;

}

Client::~Client() {
    cout << "Client: Connection closed." << endl;
    close(this->sockFD);
}

void Client::startChat() {
    thread receiveThread([&]() {
        while (true) {
            string serverMessage = connection->receiveMessage();
            if (serverMessage.empty() || serverMessage == "QUIT") {
                break;
            }
            cout << "\nServer: " << serverMessage << endl;
            cout << "You: ";
            cout.flush();
        }
    });

    string message;

    while(true) {
        cout << "You: ";
        getline(cin, message);

        connection->sendMessage(message);

        if (message == "QUIT") {
            break;
        }
    }
    receiveThread.join();
}
