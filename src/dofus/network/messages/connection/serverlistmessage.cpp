//
// serverlistmessage.cpp
// CawotteSrv
//
// Created by Luax on 7/5/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "serverlistmessage.h"

void ServerListMessage::initServerListMessage(
        std::vector<GameServerInformations> _servers,
        uint _alreadyConnectedToServerId,
        bool _canCreateNewCharacter
)
{
    servers = _servers;
    alreadyConnectedToServerId = _alreadyConnectedToServerId;
    canCreateNewCharacter = _canCreateNewCharacter;
}

ushort ServerListMessage::getId()
{
    return id;
}

std::string ServerListMessage::getName()
{
    return "ServerListMessage";
}

void ServerListMessage::serialize(BinaryWriter& writer)
{
    writer.writeShort(static_cast<short>(servers.size()));
    for (int i = 0; i < servers.size(); i++)
    {
        servers[i].serialize(writer);
    }
    writer.writeVarShort(static_cast<short>(alreadyConnectedToServerId));
    writer.writeBool(canCreateNewCharacter);
}

void ServerListMessage::deserialize(BinaryReader& reader)
{

}
