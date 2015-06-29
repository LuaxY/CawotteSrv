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

using Core::IO::BinaryReader;
using Core::IO::BinaryWriter;

namespace Dofus {
namespace Network {
namespace Messages {

class IMessage
{
public:
    virtual unsigned short getId() = 0;
    virtual std::string getName() = 0;
    virtual void serialize(BinaryWriter& writer) = 0;
    virtual bool deserialize(BinaryReader& reader) = 0;
};

}}} // Dofus::Network::Messages

#endif // CAWOTTESRV_IMESSAGE_H
