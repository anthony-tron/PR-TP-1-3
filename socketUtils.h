#ifndef SOCKETUTILS_H
#define SOCKETUTILS_H

#include <string>

namespace su
{
    std::string readEntirelyFrom(const int& fd, const unsigned& maxBufferSize = 256);
}

#endif // SOCKETUTILS_H
