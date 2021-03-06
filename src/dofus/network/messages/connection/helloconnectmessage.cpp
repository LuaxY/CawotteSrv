//
// helloconnectmessage.cpp
// CawotteSrv
//
// Created by Luax on 6/29/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "helloconnectmessage.h"

void HelloConnectMessage::initHelloConnectMessage(std::string _salt, ByteArray _key)
{
    salt = _salt;
    key = _key;
}

ushort HelloConnectMessage::getId()
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
    // TODO: Write size with writeVarInt
    writer.writeBytes(key, false);
}

void HelloConnectMessage::deserialize(BinaryReader& reader)
{
    salt = reader.readUTF();
    key = reader.readBytes();
}