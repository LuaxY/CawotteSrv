//
// generate.cpp
// CawotteSrv
//
// Created by Luax on 6/30/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "generate.h"
#include <algorithm>
#include <functional>

std::default_random_engine Generate::_generator = std::default_random_engine(std::random_device{}());

const std::string Generate::_ticketCharset = "0123456789"
        "!@#$%^&*"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

const std::string Generate::_saltCharset = "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

std::string Generate::ticket(ushort length)
{
    return randomString(length, _ticketCharset);
}

std::string Generate::salt(ushort length)
{
    return randomString(length, _saltCharset);
}

int Generate::random(ushort min, ushort max)
{
    std::uniform_int_distribution<> rand(min, max);
    return rand(_generator);
}

std::string Generate::randomString(ushort length, const std::string charset)
{
    std::string randomString;

    for (int i = 0; i < length; ++i)
    {
        int rand = random(0, static_cast<ushort>(charset.length() - 1));
        randomString += charset[rand];
    }

    return randomString;
}
