//
// generate.h
// CawotteSrv
//
// Created by Luax on 6/30/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_TICKET_H
#define CAWOTTESRV_TICKET_H

#include "core/utils/types.h"

#include <string>
#include <random>

class Generate
{
public:
    static std::string ticket(ushort length = 32);
    static std::string salt(ushort length = 8);
    static int random(ushort min = 0, ushort max = 100);

private:
    static std::default_random_engine _generator;
    static const std::string _ticketCharset;
    static const std::string _saltCharset;

    static std::string randomString(ushort length, const std::string charset);
};


#endif //CAWOTTESRV_TICKET_H
