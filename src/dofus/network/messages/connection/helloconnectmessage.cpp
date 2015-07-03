//
// helloconnectmessage.cpp
// CawotteSrv
//
// Created by Luax on 6/29/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "helloconnectmessage.h"

void HelloConnectMessage::initHelloConnectMessage(std::string _salt, std::vector<char> _key)
{
    salt = _salt;
    key = _key;
}

unsigned short HelloConnectMessage::getId()
{
    return id;
}

std::string HelloConnectMessage::getName()
{
    return "HelloConnectMessage";
}
void HelloConnectMessage::serialize(BinaryWriter& writer)
{
    writer.writeUTF(salt);
    writer.writeBytes(key);
}

void HelloConnectMessage::deserialize(BinaryReader& reader)
{
    salt = reader.readUTF();
    key = reader.readBytes();
}