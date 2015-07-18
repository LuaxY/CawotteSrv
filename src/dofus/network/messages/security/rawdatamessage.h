//
// rawdatamessage.h
// CawotteSrv
//
// Created by Luax on 7/18/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_RAWDATAMESSAGE_H
#define CAWOTTESRV_RAWDATAMESSAGE_H

#include "dofus/network/messages/imessage.h"

class RawDataMessage : public IMessage
{
public:
    void initRawDataMessage(ByteArray _content);
    ushort getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int id = 6253;

    /* VARIABLES */

    ByteArray content;
};


#endif // CAWOTTESRV_RAWDATAMESSAGE_H
