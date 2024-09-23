#pragma once

#include <exception>
#include <string>


class SockException : std::exception {
    private:
        int errorNum;
        std::string reason;
        mutable std::string formattedMessage;
    public:
        SockException(std::string reason);
        SockException(std::string reason, int errorNum);
        const char* what() const _NOEXCEPT override;
};
