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

#include <memory>


class GameMode;
class Server;

class Client
{
public:
    Client(Socket& clientSocket, GameMode* gameMode);
    void send(IMessage& message);
    void close();
    std::string toString();

private:
    void onReadable();
    void onWritable();
    void onShutdown();

    Socket& _clientSocket;
    GameMode* _gameMode;
};

#endif // CAWOTTESRV_CLIENT_H
