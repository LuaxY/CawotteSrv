//
// registringframe.cpp
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "frame.h"
#include <iostream>

bool Frame::process(Client& client, uint id, BinaryReader& reader)
{
    if (_handlers.find(id) != _handlers.end())
    {
        auto message = _messages[id]();

        if (message)
        {
            std::cout << "[" << client.toString() << "] [RCV] " <<
                message->getName() << " (" << id << ") handled by " <<
                getName() << std::endl << std::flush;

            message->deserialize(reader);
            _handlers[id](client, message);
            return true;
        }
    }

    return false;
}
