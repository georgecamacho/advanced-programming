#pragma once

#include <string>

#include "Comms.h"
#include "Connect.h"

using namespace std;

class Client : public Comms {
    public:
        Client(const char* address, int port);
        ~Client();

};
