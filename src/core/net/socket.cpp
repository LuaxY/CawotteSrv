//
// socket.cpp
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "socket.h"

#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <event2/util.h>

int Socket::getSockfd()
{
    return _sockfd;
}

std::string Socket::getAddress()
{
    return std::string(inet_ntoa(_sockaddr.sin_addr));
}

ushort Socket::getPort()
{
    return ntohs(_sockaddr.sin_port);
}

std::string Socket::toString()
{
    std::stringstream ss;
    ss << getAddress() << ":" << getPort();
    return ss.str();
}

void Socket::setNonBlocking()
{
    evutil_make_socket_nonblocking(_sockfd);
    return;

    int flags = fcntl(_sockfd, F_GETFL);

    if (flags == -1)
    {
        throw std::logic_error("can't get flags of socket descriptor");
    }

    flags |= O_NONBLOCK;

    if (fcntl(_sockfd, F_SETFL, flags))
    {
        throw std::logic_error("can't set flags of socket descriptor");
    }
}

int Socket::close()
{
    return ::close(_sockfd);
}