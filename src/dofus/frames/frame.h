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
#include "dofus/network/messages/imessage.h"

#include <map>
#include <functional>

using std::placeholders::_1;
using std::placeholders::_2;

class Frame
{
public:
    virtual uint getPriority() = 0;
    virtual std::string getName() = 0;
    bool process(Client& client, uint id, BinaryReader& reader);
    virtual void registerMessages() = 0;

protected:
    template<class T>
    using Function = std::function<void(Client&, std::shared_ptr<T>)>;
    using Handler  = std::function<void(Client&, std::shared_ptr<IMessage>)>;
    using Message  = std::function<std::shared_ptr<IMessage>()>;

    template<class T>
    void registerMessage(uint id, Function<T> function)
    {
        _handlers[id] = createHandler(function);
        _messages[id] = createMessage<T>();
    }

private:
    std::map<uint, Handler> _handlers;
    std::map<uint, Message> _messages;

    template<typename T>
    Handler createHandler(Function<T>& function)
    {
        return [function](Client& client, std::shared_ptr<IMessage> message)
        {
            function(client, std::static_pointer_cast<T>(message));
        };
    }

    template<typename T>
    Message createMessage()
    {
        return []()
        {
            return std::static_pointer_cast<IMessage>(std::make_shared<T>());
        };
    }
};

#endif // CAWOTTESRV_IFRAME_H
