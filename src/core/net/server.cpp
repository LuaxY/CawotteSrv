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

        if (_clientThreadPool.available() > 0)
        {
            std::cout << "New client" << std::endl << std::flush;

            std::shared_ptr<Client> client(new Client(*this, peer));
            _clientThreadPool.start(*client);
            _clientList.push_back(client);
        };
    }

    _clientThreadPool.joinAll();
}
