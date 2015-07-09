//
// server.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "server.h"
#include <iostream>

void Server::init(std::string ipToBind, ushort portToListen)
{
    _ipToBind = ipToBind;
    _portToBind = portToListen;

    SocketAddress socketAddress(_ipToBind, _portToBind);

    _serverSocket = new ServerSocket(socketAddress);
    _serverSocket->setReuseAddress(true);
    _serverSocket->setReusePort(true);
}

