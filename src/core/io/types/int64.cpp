//
// int64.cpp
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "int64.h"
#include <stdexcept>
#include <cmath>

Int64::Int64(unsigned int _low, unsigned int _high) :
    Binary64(_low, _high)
{
}

Int64 Int64::fromNumber(double value)
{
    return Int64(value, std::floor(value / 4294967296));
}

Int64 Int64::parseInt64(std::string str, unsigned int radix)
{
    throw std::logic_error("function not implemented");
    return Int64();
}

void Int64::setHigh(unsigned int high)
{
    internalHigh = high;
}

unsigned int Int64::getHigh()
{
    return internalHigh;
}

double Int64::toNumber()
{
    return (getHigh() * 4294967296) + low;
}

std::string Int64::toString(unsigned int radix)
{
    throw std::logic_error("function not implemented");
    return "";
}
