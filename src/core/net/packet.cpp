//
// packet.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "packet.h"
#include <stdexcept>

using Core::Net::Packet;

Packet::Packet()
{
}

Packet::~Packet()
{
}

void Packet::serialize(IMessage& message, std::vector<char>& buffer)
{
    BinaryWriter writer(buffer);
    BinaryWriter messageWriter(_data);
    message.serialize(messageWriter);

    _id = message.getId();
    _length = static_cast<unsigned int>(_data.size());
    _lengthType = computeLengthType(_length);
    _header = computeHeader(_id, _lengthType);

    if (_header == 0)
    {
        throw std::logic_error("header must be non null");
    }

    writer.writeShort(_header);

    switch (_lengthType)
    {
        case 1:
            writer.writeByte(static_cast<char>(_length));
            break;
        case 2:
            writer.writeUShort(static_cast<unsigned short>(_length));
            break;
        case 3:
            // TODO: Write for 3 bytes length
            break;
        default:
            break;
    }

    writer.writeBytes(_data, false);
}

bool Packet::deserialize(std::vector<char>& buffer)
{
    _header = 0;
    _id = 0;
    _lengthType = 0;
    _length = 0;
    _data.clear();

    BinaryReader reader(buffer);
    unsigned int countReadedBytes = 0;

    if (reader.bytesAvailable() < sizeof(_header))
    {
        return false;
    }

    _header = reader.readUShort();
    _id = getMessageId(_header);
    _lengthType = getMessageLengthType(_header);
    countReadedBytes += sizeof(_header);

    if (reader.bytesAvailable() < _lengthType)
    {
        return false;
    }

    _length = getMessageLength(_lengthType, reader);
    countReadedBytes += _lengthType;

    if (reader.bytesAvailable() < _length)
    {
        return false;
    }

    _data = reader.readBytes(_length);
    countReadedBytes += _length;

    buffer.erase(buffer.begin(), buffer.begin() + countReadedBytes);

    return true;
}

unsigned short Packet::getMessageId(unsigned short header)
{
    return header >> 2;
}

unsigned short Packet::getMessageLengthType(unsigned short header)
{
    return static_cast<unsigned short>(header & 3);
}

unsigned int Packet::getMessageLength(unsigned short lengthType, BinaryReader& reader)
{
    unsigned int length = 0;

    switch(lengthType)
    {
        case 1:
            length = static_cast<unsigned int>(reader.readByte());
            break;
        case 2:
            length = reader.readUShort();
            break;
        case 3:
            length = static_cast<unsigned int>(
                        ((reader.readByte() & 255) << 16) +
                        ((reader.readByte() & 255) << 8) +
                         (reader.readByte() & 255));
            break;
        default:
            break;
    }

    return length;
}

unsigned short Packet::computeLengthType(unsigned int length)
{
    if (length > 65535)
        return 3;
    if (length > 255)
        return 2;
    if (length > 0)
        return 1;

    return 0;
}

unsigned short Packet::computeHeader(unsigned short id, unsigned short lengthType)
{
    return id << 2 | lengthType;
}