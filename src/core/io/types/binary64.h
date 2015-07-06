//
// binary64.h
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_BINARY64_H
#define CAWOTTESRV_BINARY64_H

#include "core/utils/types.h"

class Binary64
{
public:
    Binary64(uint _low = 0, uint _high = 0);

    uint div(uint n);
    void mul(uint n);
    void add(uint n);
    void bitWiseNot();

    uint low;

protected:
    uint internalHigh;

    static const char CHAR_CODE_0 = '0';
    static const char CHAR_CODE_9 = '9';
    static const char CHAR_CODE_A = 'A';
    static const char CHAR_CODE_Z = 'Z';
};


#endif // CAWOTTESRV_BINARY64_H
