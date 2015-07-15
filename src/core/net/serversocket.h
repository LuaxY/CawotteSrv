//
// serversocket.h
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_SERVERSOCKET_H
#define CAWOTTESRV_SERVERSOCKET_H

#include "socket.h"

class ServerSocket : public Socket
{
public:
    ServerSocket(std::string ipToBind, ushort portToListen);

    void listen();
    Socket accept();

private:
    std::string _ipToBind;
    ushort _portToListen;
    static const int LISTENER_QUEUE_LIMIT = 100;
};

#endif // CAWOTTESRV_SERVERSOCKET_H
