//
// int64.h
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_INT64_H
#define CAWOTTESRV_INT64_H

#include "binary64.h"
#include <string>

class Int64 : public Binary64
{
public:
    Int64(uint _low = 0, uint _high = 0);

    static Int64 fromNumber(double value);
    static Int64 parseInt64(std::string str, uint radix = 0);

    void setHigh(uint high);
    uint getHigh();

    double toNumber();
    std::string toString(uint radix = 10);
};


#endif // CAWOTTESRV_INT64_H
