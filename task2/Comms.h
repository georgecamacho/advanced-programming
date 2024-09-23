#pragma once

#include "netinet/in.h"

class Comms {
    // these variables can only be accessed by child classes
    protected:
        int sockFD;
        sockaddr_in address;
    
    public:
        const static int SOCKET_ERROR = -1;
        Comms(const char* address, int port);


};
