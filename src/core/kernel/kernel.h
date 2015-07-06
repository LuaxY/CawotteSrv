//
// kernel.h
// CawotteSrv
//
// Created by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_KERNEL_H
#define CAWOTTESRV_KERNEL_H

#include "core/net/server.h"
#include "core/utils/singleton.h"
#include "core/utils/types.h"

class Kernel : public Singleton<Kernel>
{
public:
    void init();
    void initConfiguration();
    void initFrames();
    void initCache();

    void panic(uint errorId = 0);
    void reset(bool autoRetry = false);

private:
    Server* createServer(std::string serverMode);

    std::shared_ptr<Server> server;
};

#endif //CAWOTTESRV_KERNEL_H
