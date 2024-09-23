#include <iostream>

#include "Client.h"
#include "Server.h"
#include "SockException.h"

using namespace std;

int main() {
    char const *serverAddress = "127.0.0.1";
    int port = 31415;

    try {
        #if IS_SERVER == true
        Server server(serverAddress, port);
        server.start();
        #else
        Client client(serverAddress, port);
        client.startChat();
        #endif
    }
    catch(const SockException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
