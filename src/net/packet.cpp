//
// packet.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "packet.h"
#include <stdexcept>

using Net::Packet;

Packet::Packet(std::vector<char> buffer) :
    _buffer(buffer) // TODO: this MUST be a pointer
{
}

Packet::Packet(/*IMessage message*/int message) :
    _message(message)
{
}

Packet::~Packet()
{
}

void Packet::serialize()
{
    /*
     * TODO: serialize packet
     *
     *  Create BinaryWriter
     *
     *  header = message.getId() & 3 (TODO: check this)
     *  header = message.getSizeType() | 2
     *
     *  writeByte(header)
     *
     *  switch message.getSizeType()
     *      1:
     *          writeByte(message.getSize())
     *      2:
     *          writeUInt(message.getSize())
     *      3:
     *          TODO: write for 3 bytes size
     *
     * message.serialize()
     *
     * writeBytes(message.getData())
     */

    throw std::logic_error("function not implemented");
}

void Packet::deserialize()
{
    /*
     * TODO: deserialize packet
     *
     * Create BinaryReader with buffer
     *
     * if reader.bytesAvailable() > header size
     *      Read header
     *      Get message Id
     *      Get length size
     *
     * if reader.bytesAvailable() > length size
     *      Get length
     *
     * if reader.bytesAvailable() > data size
     *      Get Data
     *
     * Remove X bytes from beginning of buffer
     */

    throw std::logic_error("function not implemented");
}

const std::vector<char> Packet::getBuffer()
{
    return _buffer;
}

const /*IMessage*/ int Packet::getMessage()
{
    return _message;
}