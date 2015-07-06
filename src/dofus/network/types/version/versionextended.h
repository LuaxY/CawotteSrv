//
// versionextended.h
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_VERSIONEXTENDED_H
#define CAWOTTESRV_VERSIONEXTENDED_H

#include "version.h"

class VersionExtended : public Version
{
public:
    void initVersionExtended(char _install, char _technology);
    ushort getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int id = 393;

    /* VARIABLES */

    char install;
    char technology;
};


#endif // CAWOTTESRV_VERSIONEXTENDED_H
