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
#include "dofus/frames/frame.h"

class Auth : public Server
{
public:
    Auth() : Server() { };

    void init(std::string ipToBind, ushort portToListen);
    void onNewConnection(Client& client);
    bool onNewPacket(Client& client, Packet& packet);

private:
    std::vector<char> _key;
    std::vector<Frame*> _frameList;

    void initFrames();
};

#endif //CAWOTTESRV_AUTH_H
