//
// event.cpp
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "event.h"

#include <stdexcept>

Event::Event(struct event* event) :
    _event(event)
{
}

Event::~Event()
{
    event_del(_event);
}

void Event::schedule()
{
    if (event_add(_event, NULL))
    {
        throw std::logic_error("can't scheduling connection event on the event loop");
    }
}
