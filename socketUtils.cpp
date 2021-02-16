#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "socketUtils.h"

namespace su
{
    std::string readEntirelyFrom(const int& fd, const unsigned& maxBufferSize)
    {
        std::string fullResponse;

        for (;;)
        {
            char reponse[maxBufferSize];
            ssize_t nombre_octets_lus = read(fd, reponse, maxBufferSize);

            if (nombre_octets_lus == -1)
                throw std::exception();
            else if (nombre_octets_lus == 0)
                break;

            fullResponse += reponse;
        }

        return fullResponse;
    }
}
