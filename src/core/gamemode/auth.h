//
// auth.h
// CawotteSrv
//
// Created by Luax on 7/9/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_AUTH_H
#define CAWOTTESRV_AUTH_H

#include "gamemode.h"
#include "core/utils/types.h"

class Auth : public GameMode
{
public:
    Auth();

    void initFrames();
    void onNewClient(Client& client);

private:
    ByteArray _key;
};


#endif //CAWOTTESRV_AUTH_H
