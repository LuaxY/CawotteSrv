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
#include <vector>

using Dofus::Network::Messages::IMessage;

namespace Net {

class Packet
{
public:
    Packet(std::vector<char> buffer);
    Packet(IMessage message);
    ~Packet();

    void serialize();
    void deserialize();

    const std::vector<char> getBuffer();
    const IMessage getMessage();

private:
    unsigned char _header;
    unsigned int _id;
    unsigned int _sizeLenght;
    unsigned int _size;
    std::vector<char> _data;

    std::vector<char> _buffer;
    IMessage _message;
};

} // Net

#endif // CAWOTTESRV_PACKET_H
