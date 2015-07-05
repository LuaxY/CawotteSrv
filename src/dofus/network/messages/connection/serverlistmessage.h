//
// serverlistmessage.h
// CawotteSrv
//
// Created by Luax on 7/5/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_SERVERLISTMESSAGE_H
#define CAWOTTESRV_SERVERLISTMESSAGE_H

#include "dofus/network/messages/imessage.h"
#include "dofus/network/types/connection/gameserverinformations.h"

class ServerListMessage : public IMessage
{
public:
    void initServerListMessage(
        std::vector<GameServerInformations> _servers,
        unsigned int _alreadyConnectedToServerId = 0,
        bool _canCreateNewCharacter = true
    );

    unsigned short getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int id = 30;

    /* VARIABLES */

    std::vector<GameServerInformations> servers;
    unsigned int alreadyConnectedToServerId;
    bool canCreateNewCharacter;
};


#endif // CAWOTTESRV_SERVERLISTMESSAGE_H
