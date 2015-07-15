//
// eventbase.cpp
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "eventbase.h"

#include <iostream>
#include <stdexcept>

EventBase::EventBase() :
    _eventBase(event_base_new())
{
    if (!_eventBase)
    {
        throw std::logic_error("event base initialization fail");
    }
}

EventBase::~EventBase()
{
    event_base_free(_eventBase);
}

void EventBase::displayDetails()
{
    std::cout << "Using LibEvent with backend method " << event_base_get_method(_eventBase) << std::endl;

    int features = event_base_get_features(_eventBase);

    if (features & EV_FEATURE_ET)
        std::cout << "  Edge-tiggred events are supported" << std::endl;

    if (features & EV_FEATURE_O1)
        std::cout << "  O(1) event notification is supported" << std::endl;

    if (features & EV_FEATURE_FDS)
        std::cout << "  All FD types are supported" << std::endl;
}

void EventBase::dispatch()
{
    if (event_base_dispatch(_eventBase))
    {
        throw std::logic_error("error while running event loop");
    }
}

Event* EventBase::createEvent(int fd, short events, event_callback_fn callback, void* arg)
{
    return new Event(event_new(_eventBase, fd, events, callback, arg));
}

event_base* EventBase::getEventBase()
{
    return _eventBase;
}
