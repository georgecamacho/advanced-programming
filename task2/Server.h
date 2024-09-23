#pragma once

#include "Comms.h"
#include "Connection.h"

class Server : public Comms {
    private:
        Connection* connection;
    public:
        Server(const char* address, int port);
        ~Server();
        void start();
        void startChat();

};
