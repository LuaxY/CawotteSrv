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

/*
 * server;
 * init /w ip + pot
 * listen
 */

class ServerSocket : public Socket
{
public:
    ServerSocket(std::string ipToBind, ushort portToListen);

    void listen();
    Socket accept();
    void reUsePort();
    void reUseAddress();

private:
    std::string _ipToBind;
    ushort _portToListen;

    void reUse(int option);
};


#endif // CAWOTTESRV_SERVERSOCKET_H
