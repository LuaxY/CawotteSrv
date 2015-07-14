//
// socket.h
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_SOCKET_H
#define CAWOTTESRV_SOCKET_H

#include "core/utils/types.h"

#include <sys/socket.h>
#include <arpa/inet.h>
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
    void setNonblock();
    int close();

protected:
    int _sockfd;
    struct sockaddr_in _sockaddr;
};


#endif // CAWOTTESRV_SOCKET_H
