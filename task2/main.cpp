#include <iostream>

#include "Client.h"
#include "Server.h"

using namespace std;

int main() {
    char const *serverAddress = "127.0.0.1";
    int port = 31415;

    try {
        #if IS_SERVER == true
        Server* server = new Server(serverAddress, port);
        server->start();
        #else
        Client* client = new Client(serverAddress, port);
        cout << "Connection has been established with server." << endl;
        delete client;
        #endif
    }
    catch(exception e) {
        cout << "[ERROR] - error occurred during setup" << endl;
    }

    return 0;
}
