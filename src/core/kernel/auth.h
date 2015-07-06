//
// auth.h
// CawotteSrv
//
// Created by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_AUTH_H
#define CAWOTTESRV_AUTH_H

#include "core/net/server.h"
#include "core/net/client.h"

class Auth : public Server
{
public:
    Auth() : Server() { };

    void onNewConnection(Client& client);
    bool onNewPacket(Client& client, Packet& packet);
};

#endif //CAWOTTESRV_AUTH_H
