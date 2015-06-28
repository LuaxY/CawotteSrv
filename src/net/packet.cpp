//
// packet.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "packet.h"

using Net::Packet;

Packet::Packet()
{
}

Packet::~Packet()
{
}

Packet::SerialisationResult Packet::serialize()
{
    return OK;
}

Packet::SerialisationResult Packet::deserialize()
{
    return OK;
}