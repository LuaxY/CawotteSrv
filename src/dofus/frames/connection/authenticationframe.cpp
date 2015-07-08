//
// authentificationframe.cpp
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "authenticationframe.h"
#include <iostream>

#include "dofus/network/messages/connection/identificationsuccessmessage.h"
#include "dofus/network/messages/connection/serverlistmessage.h"
#include "dofus/network/enums/serverstatusenum.h"

uint AuthenticationFrame::getPriority()
{
    return 10;
}

std::string AuthenticationFrame::getName()
{
    return "AuthenticationFrame";
}

void AuthenticationFrame::registerMessages()
{
    registerMessage<IdentificationMessage>(IdentificationMessage::id, std::bind(&AuthenticationFrame::onIdentificationMessage, this, _1, _2));
}

void AuthenticationFrame::onIdentificationMessage(Client& client, std::shared_ptr<IdentificationMessage> message)
{
    //std::cout << message->lang << " " << message->serverId << std::endl << std::flush;

    IdentificationSuccessMessage ism;
    ism.initIdentificationSuccessMessage("Luax", "Luax", 1, 1, true, "Qui est le plus fort ?");
    client.send(ism);

    GameServerInformations jiva;
    jiva.initGameServerInformations(1, ServerStatusEnum::ONLINE, 0, true, 1);
    std::vector<GameServerInformations> serversList;
    serversList.push_back(jiva);

    ServerListMessage slm;
    slm.initServerListMessage(serversList, 0, true);
    client.send(slm);
}