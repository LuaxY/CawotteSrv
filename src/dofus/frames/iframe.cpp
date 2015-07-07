//
// registringframe.cpp
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "iframe.h"

bool IFrame::process(Client& client, Packet& packet)
{
    Function handler = _registeredHandlers[packet.id()];
    return handler(client, packet);
}

void IFrame::registerMessage(uint id, Function function)
{
    _registeredHandlers[id] = function;
}