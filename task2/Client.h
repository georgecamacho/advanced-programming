#pragma once

#include <string>

#include "Comms.h"
#include "Connection.h"

using namespace std;

class Client : public Comms {
    private:
        Connection* connection;
    public:
        Client(const char* address, int port);
        ~Client();
        void startChat();

};
