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

namespace Dofus {
namespace Network {
namespace Messages {

class IMessage
{
public:
    virtual unsigned short getId();

    virtual bool serialize(std::vector<char>& buffer);
    virtual bool deserialize();
};

}}} // Dofus::Network::Messages

#endif // CAWOTTESRV_IMESSAGE_H
