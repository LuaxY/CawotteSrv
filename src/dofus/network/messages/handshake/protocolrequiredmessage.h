//
// protocolrequiredmessage.h
// CawotteSrv
//
// Created by Luax on 7/3/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_PROTOCOLREQUIREDMESSAGE_H
#define CAWOTTESRV_PROTOCOLREQUIREDMESSAGE_H

#include "dofus/network/messages/imessage.h"

class ProtocolRequiredMessage : public IMessage
{
public:
    void initProtocolRequiredMessage(unsigned int _requiredVersion, unsigned int _currentVersion);
    unsigned short getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int id = 1;

    /* VARIABLES */

    unsigned int requiredVersion;
    unsigned int currentVersion;
};


#endif // CAWOTTESRV_PROTOCOLREQUIREDMESSAGE_H
