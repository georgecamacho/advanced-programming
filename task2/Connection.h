#pragma once

#include <string>

class Connection {
    private:
        static struct timeval TIMEOUT;
        static int MAX_SIZE_OF_BUFFER;
        int sock;
    public:
        Connection(int sock);
        ~Connection();
        void sendMessage(const std::string& message);
        std::string receiveMessage();
        
};
