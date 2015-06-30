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

using Core::Utils::Generate;

std::default_random_engine Generate::_generator = std::default_random_engine(std::random_device{}());

const std::string Generate::_ticketCharset = "0123456789"
        "!@#$%^&*"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

const std::string Generate::_saltCharset = "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

std::string Generate::ticket(unsigned short length)
{
    return randomString(length, _ticketCharset);
}

std::string Generate::salt(unsigned short length)
{
    return randomString(length, _saltCharset);
}

unsigned int Generate::random(unsigned short min, unsigned short max)
{
    std::uniform_int_distribution<> rand(min, max);
    return rand(_generator);
}

std::string Generate::randomString(unsigned short length, const std::string charset)
{
    std::string randomString;

    for (int i = 0; i < length; ++i)
    {
        unsigned int rand = random(0, static_cast<unsigned short>(charset.length() - 1));
        randomString += charset[rand];
    }

    return randomString;
}
