//
// version.h
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_VERSION_H
#define CAWOTTESRV_VERSION_H

#include "dofus/network/types/itype.h"

class Version : public IType
{
public:
    void initVersion(char _major, char _minor, char _release, int _revision, char _patch, char _buildType);
    ushort getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int id = 11;

    /* VARIABLES */

    char major;
    char minor;
    char release;
    int revision;
    char patch;
    char buildType;
};


#endif // CAWOTTESRV_VERSION_H
