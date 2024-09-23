#pragma once

#include "Comms.h"

class Server : public Comms {
    public:
        Server(const char* address, int port);
        ~Server();
        void start();

};
