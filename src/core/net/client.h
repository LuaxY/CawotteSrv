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
#include "socket.h"
#include "core/event/eventbase.h"

#include <memory>
#include <event2/bufferevent.h>

class GameMode;
class Server;

class Client
{
public:
    Client(Socket* clientSocket, GameMode* gameMode, EventBase* eventBase);
    void send(IMessage& message);
    void close();
    std::string toString();

private:
    static void onReadable(struct bufferevent* bufferEvent, void* arg);
    static void onWritable(struct bufferevent* bufferEvent, void* arg);
    static void onEvent(struct bufferevent* bufferEvent, short eventType, void* arg);

    Socket* _clientSocket;
    GameMode* _gameMode;
    EventBase* _eventBase;
    struct bufferevent* _bufferEvent;

    static const int SIZE_OF_BUFFER = 2048;
};

#endif // CAWOTTESRV_CLIENT_H
