//
// eventbase.h
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_EVENTBASE_H
#define CAWOTTESRV_EVENTBASE_H

#include "event.h"

class EventBase
{
public:
    EventBase();
    ~EventBase();

    void displayDetails();
    void dispatch();
    Event* createEvent(int fd, short events, event_callback_fn callback, void* arg);

private:
    struct event_base* _eventBase;
};


#endif // CAWOTTESRV_EVENTBASE_H
