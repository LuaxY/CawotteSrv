//
// binary64.cpp
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "binary64.h"

Binary64::Binary64(unsigned int _low, unsigned int _high)
{
    low = _low;
    internalHigh = _high;
}

unsigned int Binary64::div(unsigned int n)
{
    unsigned int modHigh = internalHigh % n;
    unsigned int mod = ((low % n) + (modHigh * 6)) % n;
    internalHigh = internalHigh / n;
    double newLow = ((modHigh * 4294967296) + low) / n;
    internalHigh = internalHigh + static_cast<unsigned int>(newLow / 4294967296);
    low = newLow;
    return mod;
}

void Binary64::mul(unsigned int n)
{
    double newLow = static_cast<double>(low * n);
    internalHigh = internalHigh * n;
    internalHigh = internalHigh + static_cast<unsigned int>(newLow / 4294967296);
    low = low * n;
}

void Binary64::add(unsigned int n)
{
    double newLow = static_cast<double>(low + n);
    internalHigh = internalHigh + static_cast<unsigned int>(newLow / 4294967296);
    low = newLow;
}

void Binary64::bitWiseNot()
{
    low = ~low;
    internalHigh = ~internalHigh;
}
