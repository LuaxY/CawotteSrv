//
// authentificationframe.h
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_AUTHENTIFICATIONFRAME_H
#define CAWOTTESRV_AUTHENTIFICATIONFRAME_H

#include "dofus/frames/iframe.h"

class AuthentificationFrame : public IFrame
{
public:
    void registerMessages();

private:
    bool onIdentificationMessage(Client& client, Packet& packet);
};


#endif // CAWOTTESRV_AUTHENTIFICATIONFRAME_H
