//
// uint64.cpp
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "uint64.h"
#include <stdexcept>
#include <cmath>

UInt64::UInt64(unsigned int _low, unsigned int _high) :
        Binary64(_low, _high)
{
}

UInt64 UInt64::fromNumber(double value)
{
    return UInt64(value, std::floor(value / 4294967296));
}

UInt64 UInt64::parseUInt64(std::string str, unsigned int radix)
{
    throw std::logic_error("function not implemented");
    return UInt64();
}

void UInt64::setHigh(unsigned int high)
{
    internalHigh = high;
}

unsigned int UInt64::getHigh()
{
    return internalHigh;
}

double UInt64::toNumber()
{
    return (getHigh() * 4294967296) + low;
}

std::string UInt64::toString(unsigned int radix)
{
    throw std::logic_error("function not implemented");
    return "";
}
