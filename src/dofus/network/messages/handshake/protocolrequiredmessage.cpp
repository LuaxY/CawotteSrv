//
// protocolrequiredmessage.cpp
// CawotteSrv
//
// Created by Luax on 7/3/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "protocolrequiredmessage.h"

void ProtocolRequiredMessage::initProtocolRequiredMessage(uint _requiredVersion, uint _currentVersion)
{
    requiredVersion = _requiredVersion;
    currentVersion = _currentVersion;
}

ushort ProtocolRequiredMessage::getId()
{
    return id;
}

std::string ProtocolRequiredMessage::getName()
{
    return "ProtocolRequiredMessage";
}

void ProtocolRequiredMessage::serialize(BinaryWriter& writer)
{
    writer.writeUInt(requiredVersion);
    writer.writeUInt(currentVersion);
}

void ProtocolRequiredMessage::deserialize(BinaryReader& reader)
{
    requiredVersion = reader.readUInt();
    currentVersion = reader.readUInt();
}
