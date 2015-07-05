//
// serverstatusenum.h
// CawotteSrv
//
// Created by Luax on 7/5/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_SERVERSTATUSENUM_H
#define CAWOTTESRV_SERVERSTATUSENUM_H

class ServerStatusEnum
{
public:
    static const int STATUS_UNKNOWN = 0;
    static const int OFFLINE = 1;
    static const int STARTING = 2;
    static const int ONLINE = 3;
    static const int NOJOIN = 4;
    static const int SAVING = 5;
    static const int STOPING = 6;
    static const int FULL = 7;
};

#endif // CAWOTTESRV_SERVERSTATUSENUM_H
