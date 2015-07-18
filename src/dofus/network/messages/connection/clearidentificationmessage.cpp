//
// clearidentificationmessage.cpp
// CawotteSrv
//
// Created by Luax on 7/18/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "clearidentificationmessage.h"

void ClearIdentificationMessage::initClearIdentificationMessage(std::string _username, std::string _password)
{
    usename = _username;
    password = _password;
}

ushort ClearIdentificationMessage::getId()
{
    return id;
}

std::string ClearIdentificationMessage::getName()
{
    return "ClearIdentificationMessage";
}
void ClearIdentificationMessage::serialize(BinaryWriter& writer)
{
    writer.writeUTF(usename);
    writer.writeUTF(password);
}

void IdentificationMessage::deserialize(BinaryReader& reader)
{
    usename = reader.readUTF();
    password = reader.readUTF();
}
