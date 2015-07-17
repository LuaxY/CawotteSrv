//
// kernel.h
// CawotteSrv
//
// Created by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_KERNEL_H
#define CAWOTTESRV_KERNEL_H

#include "core/utils/singleton.h"
#include "core/utils/types.h"
#include "core/gamemode/gamemode.h"

class Kernel : public Singleton<Kernel>
{
public:
    void init(std::string configFile);
    void initConfiguration(std::string configFile);
    void initCache();

    GameMode* gameMode();
    void panic(uint errorId = 0);
    void reset(bool autoRetry = false);

private:
    GameMode* _gameMode;

    void createGameMode(std::string gameMode);
};

#endif //CAWOTTESRV_KERNEL_H
