//
// registringframe.cpp
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "frame.h"

bool Frame::process(Client& client, uint id, BinaryReader& reader)
{
    if (_handlers.find(id) != _handlers.end())
    {
        auto message1 = _messages[id]();

        if (message1)
        {
            message1->deserialize(reader);
            _handlers[id](client, message1);
        }
    }

    return false;
}
