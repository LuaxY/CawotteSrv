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
#include <event2/util.h>

#ifndef _WIN32
    #include <unistd.h>
#endif

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
}

void Socket::reUsePort()
{
#ifdef SO_REUSEPORT
    setOption(SO_REUSEPORT, 1);
#endif
}

void Socket::reUseAddress()
{
    setOption(SO_REUSEADDR, 1);
}

void Socket::setOption(int option, char flag)
{
    setsockopt(_sockfd, SOL_SOCKET, option, &flag, sizeof(flag));
}

int Socket::close()
{
#ifdef _WIN32
    return closesocket(_sockfd);
#else
    return ::close(_sockfd);
#endif
}