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

class Auth : public GameMode
{
public:
    Auth();

    void initFrames();
    void onNewClient(Client& client);
    std::string getHost();
    ushort getPort();

private:
    ByteArray _key;
    static const int SIZE_OF_SALT = 32;
};


#endif //CAWOTTESRV_AUTH_H
