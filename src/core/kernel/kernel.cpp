//
// kernel.cpp
// CawotteSrv
//
// Created by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "kernel.h"
#include "core/config/config.h"
#include "core/net/server.h"
#include <iostream>

using Poco::Thread;

void Kernel::init()
{
    initConfiguration();
    initCache();

    Server server(
            Config::instance().getString("auth_server.host", "0.0.0.0"),
            static_cast<unsigned short>(Config::instance().getInt("auth_server.port", 5555)));

    Thread serverThread;
    serverThread.start(server);
    serverThread.join();

    initFrames();
}

void Kernel::initConfiguration()
{
    try
    {
        Config::create();
        Config::instance().init("./config/cawotte.ini");
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

void Kernel::panic(unsigned int errorId)
{

}

void Kernel::reset(bool autoRetry)
{

}

