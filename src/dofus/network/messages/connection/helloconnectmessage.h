//
// helloconnectmessage.h
// CawotteSrv
//
// Created by Luax on 6/29/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_HELLOCONNECTMESSAGE_H
#define CAWOTTESRV_HELLOCONNECTMESSAGE_H

#include "dofus/network/messages/imessage.h"

using Dofus::Network::Messages::IMessage;

class HelloConnectMessage : public IMessage
{
public:
    HelloConnectMessage(std::string _salt, std::vector<char> _key);
    unsigned short getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    bool deserialize(BinaryReader& reader);

    static const int id = 3;

    /* VARIABLES */

    std::string salt;
    std::vector<char> key;
};

#endif //CAWOTTESRV_HELLOCONNECTMESSAGE_H
