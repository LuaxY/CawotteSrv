//
// generate.h
// CawotteSrv
//
// Created by Luax on 6/30/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_TICKET_H
#define CAWOTTESRV_TICKET_H

#include <string>
#include <random>

namespace Core {
namespace Utils {

class Generate
{
public:
    static void init();
    static std::string ticket(unsigned short length = 32);
    static std::string salt(unsigned short length = 8);
    static unsigned int random(unsigned short min = 0, unsigned short max = 100);

private:
    static std::default_random_engine _generator;
    static const std::string _ticketCharset;
    static const std::string _saltCharset;

    static std::string randomString(unsigned short length, const std::string charset);
};

}} // Core::Utils

#endif //CAWOTTESRV_TICKET_H
