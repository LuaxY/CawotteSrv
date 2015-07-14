//
// event.h
// CawotteSrv
//
// Created by Luax on 7/14/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_EVENT_H
#define CAWOTTESRV_EVENT_H

#include <event2/event.h>
#include <event2/event_struct.h>

class Event
{
public:
    Event(struct event* event);
    ~Event();

    void schedule();

private:
    struct event* _event;
};


#endif // CAWOTTESRV_EVENT_H
