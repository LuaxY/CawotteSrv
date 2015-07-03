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

class Kernel : public Singleton<Kernel>
{
public:
    void init();
    void initConfiguration();
    void initFrames();
    void initCache();

    void panic(unsigned int errorId = 0);
    void reset(bool autoRetry = false);

private:
};

#endif //CAWOTTESRV_KERNEL_H