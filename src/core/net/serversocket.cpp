//
// serversocket.cpp
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "serversocket.h"

#include <cstring>
#include <stdexcept>
#include <event2/util.h>

ServerSocket::ServerSocket(std::string ipToBind, ushort portToListen) :
    _ipToBind(ipToBind),
    _portToListen(portToListen)
{
    memset(&_sockaddr, 0, sizeof(sockaddr));
    _sockaddr.sin_family = AF_INET;
    _sockaddr.sin_port = htons(_portToListen);
    inet_aton(_ipToBind.c_str(), &_sockaddr.sin_addr);

    _sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bind(_sockfd, (struct sockaddr*)&_sockaddr, static_cast<socklen_t>(sizeof(_sockaddr)));
}

void ServerSocket::listen()
{
    ::listen(_sockfd, LISTENER_QUEUE_LIMIT); // MAX_CLIENTS
}

Socket ServerSocket::accept()
{
    struct sockaddr_in peerSockaddr;
    socklen_t peerSockaddrLen = sizeof(peerSockaddr);

    int peerSockfd = ::accept(_sockfd, (struct sockaddr*)&peerSockaddr, &peerSockaddrLen);

    if (peerSockfd < 0)
    {
        if (errno != EWOULDBLOCK && errno != EAGAIN)
        {
            throw std::logic_error("error while acception an incoming connection");
        }
    }

    return Socket(peerSockfd, peerSockaddr);
}

void ServerSocket::reUsePort()
{
    reUse(SO_REUSEPORT);
}

void ServerSocket::reUseAddress()
{
    evutil_make_listen_socket_reuseable(_sockfd);
    //reUse(SO_REUSEADDR);

}

void ServerSocket::reUse(int option)
{
    int reuse = 1;
    setsockopt(_sockfd, SOL_SOCKET, option, &reuse, sizeof(reuse));
}
