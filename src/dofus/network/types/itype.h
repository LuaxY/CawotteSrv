//
// itype.h
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_ITYPE_H
#define CAWOTTESRV_ITYPE_H

#include <vector>
#include <string>

#include "core/io/binaryreader.h"
#include "core/io/binarywriter.h"
#include "core/utils/booleanbytewrapper.h"

class IType
{
public:
    virtual unsigned short getId() = 0;
    virtual std::string getName() = 0;
    virtual void serialize(BinaryWriter& writer) = 0;
    virtual void deserialize(BinaryReader& reader) = 0;
};

#endif // CAWOTTESRV_ITYPE_H
