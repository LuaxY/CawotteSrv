//
// gameserverinformations.cpp
// CawotteSrv
//
// Created by Luax on 7/5/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "gameserverinformations.h"

void GameServerInformations::initGameServerInformations(
    unsigned int _id,
    unsigned int _status,
    unsigned int _completion,
    bool _isSelectable,
    unsigned int _characterCount,
    double _date
)
{
    id = _id;
    status = _status;
    completion = _completion;
    isSelectable = _isSelectable;
    characterCount = _characterCount;
    date = _date;
}

unsigned short GameServerInformations::getId()
{
    return __id;
}

std::string GameServerInformations::getName()
{
    return "GameServerInformations";
}

void GameServerInformations::serialize(BinaryWriter& writer)
{
    writer.writeVarShort(static_cast<short>(id));
    writer.writeByte(static_cast<char>(status));
    writer.writeByte(static_cast<char>(completion));
    writer.writeBool(isSelectable);
    writer.writeByte(static_cast<char>(characterCount));
    writer.writeDouble(date);
}

void GameServerInformations::deserialize(BinaryReader& reader)
{

}
