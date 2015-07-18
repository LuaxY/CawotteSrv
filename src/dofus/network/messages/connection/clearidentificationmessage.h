//
// clearidentificationmessage.h
// CawotteSrv
//
// Created by Luax on 7/18/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_CLEARIDENTIFICATIONMESSAGE_H
#define CAWOTTESRV_CLEARIDENTIFICATIONMESSAGE_H

#include "dofus/network/messages/imessage.h"

class ClearIdentificationMessage : public IMessage
{
public:
    void initClearIdentificationMessage(std::string _username, std::string _password);
    ushort getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int id = 888;

    /* VARIABLES */

    std::string username;
    std::string password;
};


#endif // CAWOTTESRV_CLEARIDENTIFICATIONMESSAGE_H
