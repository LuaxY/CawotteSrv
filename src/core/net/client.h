//
// client.h
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_CLIENT_H
#define CAWOTTESRV_CLIENT_H

#include "packet.h"

#include <memory>

#include <Poco/Net/StreamSocket.h>

class GameMode;

class Server;

using namespace Poco::Net;

class Client
{
public:
    Client(StreamSocket& clientSocket);
    void send(IMessage& message);
    void close();
    std::string toString();

private:
    void onReadable();
    void onWritable();
    void onShutdown();

    StreamSocket& _clientSocket;
    GameMode* _gameMode;
};

#endif // CAWOTTESRV_CLIENT_H
