//
// socket.h
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_SOCKET_H
#define CAWOTTESRV_SOCKET_H

#ifdef _WIN32
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
#endif

#include "core/utils/types.h"

#include <string>

class Socket
{
public:
    Socket() { }
    Socket(int sockfd, struct sockaddr_in sockaddr) :
        _sockfd(sockfd),
        _sockaddr(sockaddr)
    { }

    int getSockfd();
    std::string getAddress();
    ushort getPort();
    std::string toString();
    void setNonBlocking();
    void reUsePort();
    void reUseAddress();
    int close();

protected:
    int _sockfd;
    struct sockaddr_in _sockaddr;
    void setOption(int option, char flag);
};

#endif // CAWOTTESRV_SOCKET_H
