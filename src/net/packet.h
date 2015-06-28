//
// packet.h
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_PACKET_H
#define CAWOTTESRV_PACKET_H

#include <vector>

namespace Net {

class Packet
{
public:
    Packet();
    ~Packet();

    void serialize();
    void deserialize();

private:
    unsigned char _header;
    unsigned int _id;
    unsigned int _sizeLenght;
    unsigned long _size;
    std::vector<char> _data;
};

} // Net

#endif // CAWOTTESRV_PACKET_H
