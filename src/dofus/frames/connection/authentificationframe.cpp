//
// authentificationframe.cpp
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "authentificationframe.h"
#include "dofus/network/messages/connection/identificationmessage.h"

#include <iostream>

using std::placeholders::_1;
using std::placeholders::_2;

void AuthentificationFrame::registerMessages()
{
    registerMessage(4, std::bind(&AuthentificationFrame::onIdentificationMessage, this, _1, _2));
}

bool AuthentificationFrame::onIdentificationMessage(Client& client, Packet& packet)
{
    IdentificationMessage im;
    BinaryReader reader(packet.data());
    im.deserialize(reader);

    //IdentificationMessage& im = reinterpret_cast<IdentificationMessage&>(message);
    std::cout << im.lang << " " << im.serverId << std::endl << std::flush;

    return true;
}