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

#include <Poco/AutoPtr.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketNotification.h>

class GameMode;

class Server;

using namespace Poco;
using namespace Poco::Net;

class Client
{
public:
    Client(StreamSocket& clientSocket, SocketReactor& reactor);
    void send(IMessage& message);
    void close();
    std::string toString();

private:
    void onReadable(const AutoPtr<ReadableNotification>& notification);
    void onWritable(const AutoPtr<WritableNotification>& notification);
    void onShutdown(const AutoPtr<ShutdownNotification>& notification);

    StreamSocket& _clientSocket;
    SocketReactor& _reactor;
    GameMode* _gameMode;
};

#endif // CAWOTTESRV_CLIENT_H
