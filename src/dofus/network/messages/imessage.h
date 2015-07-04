//
// imessage.h
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_IMESSAGE_H
#define CAWOTTESRV_IMESSAGE_H

#include <vector>
#include <string>

#include "core/io/binaryreader.h"
#include "core/io/binarywriter.h"
#include "core/utils/booleanbytewrapper.h"

class IMessage
{
public:
    virtual unsigned short getId() = 0;
    virtual std::string getName() = 0;
    virtual void serialize(BinaryWriter& writer) = 0;
    virtual void deserialize(BinaryReader& reader) = 0;
};

#endif // CAWOTTESRV_IMESSAGE_H
