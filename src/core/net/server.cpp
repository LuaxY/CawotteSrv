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
        Socket* clientSocket = new Socket(pThis->_serverSocket->accept());
        clientSocket->setNonBlocking();
        Client* client = new Client(clientSocket, pThis->_gameMode, pThis->_eventBase);
        // TODO: Store client in vector
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return;
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
        _serverSocket->setNonBlocking();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Listening on " << _serverSocket->toString() << std::endl;

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
