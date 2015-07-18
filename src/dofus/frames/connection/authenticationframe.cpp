//
// authentificationframe.cpp
// CawotteSrv
//
// Created by Luax on 7/7/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "authenticationframe.h"

#include <iostream>
#include <fstream>

#include "dofus/network/messages/connection/identificationsuccessmessage.h"
#include "dofus/network/messages/connection/serverlistmessage.h"
#include "dofus/network/messages/security/rawdatamessage.h"
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
    register_message(IdentificationMessage, AuthenticationFrame::onIdentificationMessage);
    register_message(ClearIdentificationMessage, AuthenticationFrame::onClearIdentificationMessage);
}

void AuthenticationFrame::onIdentificationMessage(Client& client, std::shared_ptr<IdentificationMessage> message)
{
    ByteArray authPatch;
    std::ifstream authPatchFile("tools/AuthPatch/bin/AuthPatch.swf", std::ios::binary);
    std::copy(std::istreambuf_iterator<char>(authPatchFile), std::istreambuf_iterator<char>(), std::back_inserter(authPatch));

    RawDataMessage rdm;
    rdm.initRawDataMessage(authPatch);
    client.send(rdm);
}

void AuthenticationFrame::onClearIdentificationMessage(Client& client, std::shared_ptr<ClearIdentificationMessage> message)
{
    // std::cout << message->username << " " << message->password << std::endl;

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