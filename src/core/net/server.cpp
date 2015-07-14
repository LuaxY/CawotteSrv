//
// server.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "server.h"

#include <iostream>

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
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Server::run()
{
    _eventBase = new EventBase();
    _eventBase->displayDetails();

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

    Event* connectEvent = _eventBase->createEvent(_serverSocket->getSockfd(), EV_READ | EV_PERSIST, &Server::loop, (void*)this);
    connectEvent->schedule();

    _eventBase->dispatch();

    /*
     * Server stopped
     * TODO: clean up and close open connections
     */

    delete connectEvent;
    delete _eventBase;

    if (_serverSocket->close())
    {
        throw std::logic_error("error while closing listening socket");
    }
}
