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
#include "core/gamemode/auth.h"

#include <iostream>

void Kernel::init(std::string configFile)
{
    initConfiguration(configFile);
    initCache();

    try
    {
        createGameMode("auth");
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl << std::flush;
    }

    std::string host = Config::instance().getString("auth_server.host", "0.0.0.0");
    ushort port = static_cast<ushort>(Config::instance().getInt("auth_server.port", 5555));

    Server server;
    server.init(host, port, _gameMode);
    server.run(); // WARN: blocking function !!
}

void Kernel::initConfiguration(std::string configFile)
{
    try
    {
        Config::create();
        Config::instance().init(configFile);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
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

void Kernel::createGameMode(std::string gameMode)
{
    if (gameMode == "auth") { _gameMode = new Auth(); return; }
    //if (gameMode == "world") { _gameMode.reset(new World); return; }

    throw std::logic_error("game mode not found");
}


GameMode* Kernel::gameMode()
{
    return _gameMode;
}