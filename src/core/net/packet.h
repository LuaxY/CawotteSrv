//
// packet.h
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_PACKET_H
#define CAWOTTESRV_PACKET_H

#include "dofus/network/messages/imessage.h"
#include "core/io/binaryreader.h"
#include "core/io/binarywriter.h"

class Packet
{
public:
    Packet();
    ~Packet();

    void serialize(IMessage& message, ByteArray& buffer);
    bool deserialize(ByteArray& buffer);

    ushort id();
    uint length();
    ByteArray data();

private:
    ushort _header;
    ushort _id;
    ushort _lengthType;
    uint _length;
    ByteArray _data;

    ushort getMessageId(ushort header);
    ushort getMessageLengthType(ushort header);
    uint getMessageLength(ushort lengthType, BinaryReader& reader);
    ushort computeLengthType(uint length);
    ushort computeHeader(ushort id, ushort lengthType);
};

#endif // CAWOTTESRV_PACKET_H
