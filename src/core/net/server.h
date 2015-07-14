//
// server.h
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_SERVER_H
#define CAWOTTESRV_SERVER_H

#include <string>
#include <memory>
#include <vector>

#include "client.h"
#include "serversocket.h"
#include "core/utils/types.h"
#include "core/utils/singleton.h"
#include "core/event/eventbase.h"

class Server
{
public:
    void init(std::string ipToBind, ushort portToListen, GameMode* gameMode);
    void run();

private:
    std::string _ipToBind;
    ushort _portToListen;
    ServerSocket* _serverSocket;
    GameMode* _gameMode;
    EventBase* _eventBase;

    static void loop(int sockfd, short eventType, void* arg);
};

#endif // CAWOTTESRV_SERVER_H
