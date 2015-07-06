//
// kernel.cpp
// CawotteSrv
//
// Created by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "kernel.h"
#include "core/config/config.h"
#include "auth.h"
#include <iostream>

using Poco::Thread;

void Kernel::init()
{
    initConfiguration();
    initCache();

    std::string serverMode = "auth";

    server.reset(createServer(serverMode));
    if (server == nullptr)
    {
        // TODO: log this shit
        throw std::logic_error("no game server mode found");
    }

    std::string host = Config::instance().getString("auth_server.host", "0.0.0.0");
    ushort port = static_cast<ushort>(Config::instance().getInt("auth_server.port", 5555));

    server->init(host, port);

    Thread serverThread;
    serverThread.start(*server.get());
    serverThread.join();

    initFrames();
}

void Kernel::initConfiguration()
{
    try
    {
        Config::create();
        Config::instance().init("config/cawotte.ini");
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Kernel::initFrames()
{

}

void Kernel::initCache()
{

}

void Kernel::panic(uint errorId)
{

}

void Kernel::reset(bool autoRetry)
{

}

Server* Kernel::createServer(std::string serverMode)
{
    if (serverMode == "auth")  return new Auth();
    //if (serverMode == "world") return new World();

    return nullptr;
}