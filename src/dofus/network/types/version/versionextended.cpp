//
// versionextended.cpp
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "versionextended.h"

void VersionExtended::initVersionExtended(char _install, char _technology)
{
    install = _install;
    technology = _technology;
}

unsigned short VersionExtended::getId()
{
    return id;
}

std::string VersionExtended::getName()
{
    return "VersionExtended";
}
void VersionExtended::serialize(BinaryWriter& writer)
{
    serialize(writer);

    writer.writeByte(install);
    writer.writeByte(technology);
}

void VersionExtended::deserialize(BinaryReader& reader)
{
    deserialize(reader);

    install = reader.readByte();
    technology = reader.readByte();
}