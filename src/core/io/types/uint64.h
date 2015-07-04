//
// uint64.h
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_UINT64_H
#define CAWOTTESRV_UINT64_H

#include "binary64.h"
#include <string>

class UInt64 : public Binary64
{
public:
    UInt64(unsigned int _low = 0, unsigned int _high = 0);

    static UInt64 fromNumber(double value);
    static UInt64 parseUInt64(std::string str, unsigned int radix = 0);

    void setHigh(unsigned int high);
    unsigned int getHigh();

    double toNumber();
    std::string toString(unsigned int radix = 10);
};


#endif // CAWOTTESRV_UINT64_H
