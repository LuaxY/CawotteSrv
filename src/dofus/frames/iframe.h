//
// iframe.h
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_IFRAME_H
#define CAWOTTESRV_IFRAME_H

#include "core/utils/types.h"
#include "core/net/client.h"
#include "core/net/packet.h"

#include <map>
#include <functional>

class IFrame
{
public:
    //uint getPriority();
    //virtual std::string getName() = 0;
    bool process(Client& client, Packet& packet);

protected:
    using Function = std::function<bool(Client&, Packet&)>;
    virtual void registerMessages() = 0;
    void registerMessage(uint id, Function function);

private:
    std::map<uint, Function> _registeredHandlers;
};

#endif // CAWOTTESRV_IFRAME_H
