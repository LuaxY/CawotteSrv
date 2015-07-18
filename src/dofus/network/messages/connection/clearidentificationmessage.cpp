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
    username = _username;
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
    writer.writeUTF(username);
    writer.writeUTF(password);
}

void ClearIdentificationMessage::deserialize(BinaryReader& reader)
{
    username = reader.readUTF();
    password = reader.readUTF();
}
