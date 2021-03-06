//
// gamemode.h
// CawotteSrv
//
// Created by Luax on 7/9/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_GAMEMODE_H
#define CAWOTTESRV_GAMEMODE_H

#include "core/net/client.h"
#include "core/utils/singleton.h"
#include "core/utils/types.h"
#include "dofus/frames/frame.h"

class Class;

class GameMode
{
public:
    virtual void initFrames() { };

    void loadFrames()
    {
        for (Frame* frame : _frameList)
        {
            frame->registerMessages();
        }
    }

    virtual void onNewClient(Client& client) { };

    bool onNewPacket(Client& client, Packet& packet)
    {
        BinaryReader reader(packet.data());

        for (Frame* frame : _frameList)
        {
            if (frame->process(client, packet.id(), reader))
            {
                return true;
            }
        }

        return false;
    }

    virtual std::string getHost() { return "0.0.0.0"; }
    virtual ushort getPort() { return 0; }

    std::vector<Frame*> _frameList;
    std::vector<Client> _clientList;
};

#endif //CAWOTTESRV_GAMEMODE_H
