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

void Server::run()
{
    /*
    SocketAcceptor<Client> acceptor(*_serverSocket, _reactor);

    Thread thread;
    thread.start(_reactor);

    thread.join();
    _reactor.stop();
     */

    struct event_base* base = event_base_new();

    if (!base)
    {
        throw std::logic_error("event base initialization fail");
    }

    std::cout << "Using Libevent with backend method " << event_base_get_method(base) << std::endl;

    int features = event_base_get_features(base);

    if (features & EV_FEATURE_ET)
        std::cout << "  Edge-tiggred events are supported" << std::endl;

    if (features & EV_FEATURE_O1)
        std::cout << "  O(1) event notification is supported" << std::endl;

    if (features & EV_FEATURE_FDS)
        std::cout << "  All FD types are supported" << std::endl;

    //event_new(base, _serverSocket.soc)

    //event_base_set(base, )

    // free event base
    event_base_free(base);
}
