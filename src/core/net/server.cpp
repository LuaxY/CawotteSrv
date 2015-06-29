//
// server.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "server.h"
#include <iostream>

using Core::Net::Server;

Server::Server(std::string ipToBind, unsigned short portToListen) :
   _ipToBind(ipToBind),
   _portToBind(portToListen),
   _clientThreadPool(1, 100)
{
}

void Server::run()
{
    SocketAddress socketAddress(_ipToBind, _portToBind);

    _serverSocket = std::unique_ptr<ServerSocket>(new ServerSocket(socketAddress));
    _serverSocket->setReuseAddress(true);
    _serverSocket->setReusePort(true);

    for (;;)
    {
        StreamSocket peer = _serverSocket->acceptConnection();

        std::cout << "New client" << std::endl << std::flush;

        std::shared_ptr<Client> client(new Client(peer));
        _clientThreadPool.start(*client);
        _clientList.push_back(client);
    }

    _clientThreadPool.joinAll();
}