#include "SockException.h"

#include <cstring>

using namespace std;

SockException::SockException(string reason) : reason(reason), errorNum(0){}

SockException::SockException(string reason, int errorNum) : reason(reason), errorNum(errorNum){}

const char* SockException::what() const _NOEXCEPT {
    if (errorNum != 0) {
        formattedMessage = "SockException: " + reason + " (Error: " + string(strerror(errorNum)) + ")";
        
    } else {
        formattedMessage = "SockException: " + reason;
    }

    return formattedMessage.c_str();
}
