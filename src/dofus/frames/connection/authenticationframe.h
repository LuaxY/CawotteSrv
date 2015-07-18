//
// authentificationframe.h
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_AUTHENTIFICATIONFRAME_H
#define CAWOTTESRV_AUTHENTIFICATIONFRAME_H

#include "dofus/frames/frame.h"

#include "dofus/network/messages/connection/identificationmessage.h"
#include "dofus/network/messages/connection/clearidentificationmessage.h"

class AuthenticationFrame : public Frame
{
public:
    uint getPriority();
    std::string getName();
    void registerMessages();

private:
    void onIdentificationMessage(Client& client, std::shared_ptr<IdentificationMessage> message);
    void onClearIdentificationMessage(Client& client, std::shared_ptr<ClearIdentificationMessage> message);

    uint _priority = 10;
};


#endif // CAWOTTESRV_AUTHENTIFICATIONFRAME_H
