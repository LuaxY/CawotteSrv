//
// server.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "server.h"

#include <iostream>
#include <event2/event_struct.h>
#include <core/kernel/kernel.h>

void Server::init(std::string ipToBind, ushort portToListen, GameMode* gameMode)
{
    _ipToBind = ipToBind;
    _portToListen = portToListen;
    _gameMode = gameMode;

    _serverSocket = new ServerSocket(_ipToBind, _portToListen);
}

void Server::loop(int /*sockfd*/, short eventType, void* arg)
{
    if (!(eventType & EV_READ))
    {
        throw std::logic_error("unknown event type");
    }

    Server* pThis = (Server*)arg;

    try
    {
        Socket clientSocket = pThis->_serverSocket->accept();
        Client client(clientSocket, pThis->_gameMode); // + event
        pThis->_gameMode->onNewClient(client);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Server::run()
{
    struct event_base* event_loop = event_base_new();

    if (!event_loop)
    {
        throw std::logic_error("event base initialization fail");
    }

    std::cout << "Using LibEvent with backend method " << event_base_get_method(event_loop) << std::endl;

    int features = event_base_get_features(event_loop);

    if (features & EV_FEATURE_ET)
        std::cout << "  Edge-tiggred events are supported" << std::endl;

    if (features & EV_FEATURE_O1)
        std::cout << "  O(1) event notification is supported" << std::endl;

    if (features & EV_FEATURE_FDS)
        std::cout << "  All FD types are supported" << std::endl;

    try
    {
        _serverSocket->listen();
        _serverSocket->reUseAddress();
        _serverSocket->reUsePort();
        _serverSocket->setNonblock();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    struct event* connect_event = event_new(event_loop, _serverSocket->getSockfd(), EV_READ | EV_PERSIST, &Server::loop, (void*)this);

    if (event_add(connect_event, NULL))
    {
        throw std::logic_error("can't scheduling connection event on the event loop");
    }

    if (event_base_dispatch(event_loop))
    {
        throw std::logic_error("error while running event loop");
    }

    // Server stop

    // TODO: clean up and close open connections

    if (event_del(connect_event))
    {
        throw std::logic_error("can't remove connectyion event from the event loop");
    }

    event_base_free(event_loop);

    if (_serverSocket->close())
    {
        throw std::logic_error("error while closing listening socket");
    }
}
