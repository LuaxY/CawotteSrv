//
// rawdatamessage.cpp
// CawotteSrv
//
// Created by Luax on 7/18/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "rawdatamessage.h"

void RawDataMessage::initRawDataMessage(ByteArray _content)
{
    content = _content;
}

ushort RawDataMessage::getId()
{
    return id;
}

std::string RawDataMessage::getName()
{
    return "RawDataMessage";
}

void RawDataMessage::serialize(BinaryWriter& writer)
{
    writer.writeVarInt(content.size());

    for (int i = 0; i < content.size(); ++i)
    {
        writer.writeByte(content[i]);
    }
}

void RawDataMessage::deserialize(BinaryReader& reader)
{

}
