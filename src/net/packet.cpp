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

Packet::Packet()
{
}

Packet::~Packet()
{
}

void Packet::serialize()
{
    throw std::logic_error("function not implemented");
}

void Packet::deserialize()
{
    throw std::logic_error("function not implemented");
}