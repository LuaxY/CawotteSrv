//
// auth.cpp
// CawotteSrv
//
// Created by Luax on 7/9/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "auth.h"
#include "core/config/config.h"
#include "core/utils/generate.h"

#include <iostream>
#include <fstream>

#include "dofus/network/messages/connection/helloconnectmessage.h"
#include "dofus/network/messages/handshake/protocolrequiredmessage.h"
#include "dofus/frames/connection/authenticationframe.h"

#define SIZE_OF_SALT 32

Auth::Auth()
{
    std::cout << "[GameMode] Auth started" << std::endl << std::flush;

    std::ifstream keyFile("key/dofus.key", std::ios::binary);
    std::copy(std::istreambuf_iterator<char>(keyFile), std::istreambuf_iterator<char>(), std::back_inserter(_key));

    initFrames();
}

void Auth::initFrames()
{
    _frameList.push_back(new AuthenticationFrame);

    loadFrames();
}

std::string Auth::getHost()
{
    return Config::instance().getString("auth.host", "0.0.0.0");
}

ushort Auth::getPort()
{
    return static_cast<ushort>(Config::instance().getInt("auth.port", 5555));
}

void Auth::onNewClient(Client& client)
{
    _clientList.push_back(client);

    std::string salt = Generate::salt(SIZE_OF_SALT);

    HelloConnectMessage hcm;
    hcm.initHelloConnectMessage(salt, _key);
    client.send(hcm);

    int currentVersion = Config::instance().getInt("auth.current_version", 0);
    int requiredVersion = Config::instance().getInt("auth.required_version", 0);

    ProtocolRequiredMessage prm;
    prm.initProtocolRequiredMessage(currentVersion, requiredVersion);
    client.send(prm);
}
