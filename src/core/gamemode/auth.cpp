//
// auth.cpp
// CawotteSrv
//
// Created by Luax on 7/9/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "auth.h"
#include "core/utils/generate.h"

#include <iostream>
#include <fstream>

#include "dofus/network/messages/connection/helloconnectmessage.h"
#include "dofus/network/messages/handshake/protocolrequiredmessage.h"
#include "dofus/frames/connection/authenticationframe.h"

#define SIZE_OF_SALT 32

Auth::Auth()
{
    std::cout << "Auth" << std::endl << std::flush;

    std::ifstream keyFile("key/dofus.key", std::ios::binary);
    std::copy(std::istreambuf_iterator<char>(keyFile), std::istreambuf_iterator<char>(), std::back_inserter(_key));

    initFrames();
}

void Auth::initFrames()
{
    _frameList.push_back(new AuthenticationFrame);

    loadFrames();
}

void Auth::onNewClient(Client& client)
{
    _clientList.push_back(client);

    std::string salt = Generate::salt(SIZE_OF_SALT);

    HelloConnectMessage hcm;
    hcm.initHelloConnectMessage(salt, _key);
    client.send(hcm);

    ProtocolRequiredMessage prm;
    prm.initProtocolRequiredMessage(1645, 1645); // current, required
    client.send(prm);
}
