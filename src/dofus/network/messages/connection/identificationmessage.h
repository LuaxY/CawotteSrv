//
// identificationmessage.h
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_IDENTIFICATIONMESSAGE_H
#define CAWOTTESRV_IDENTIFICATIONMESSAGE_H

#include "dofus/network/messages/imessage.h"
#include "dofus/network/types/version/versionextended.h"

class IdentificationMessage : public IMessage
{
public:
    void initIdentificationMessage();
    unsigned short getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int id = 4;

    /* VARIABLES */

    bool autoConnect;
    bool useCertificate;
    bool useLoginToken;
    VersionExtended version;
    std::string lang;
    std::vector<char> credentials;
    short serverId;
    long sessionOptionalSalt;
    std::vector<unsigned short> failedAttempts;
};


#endif // CAWOTTESRV_IDENTIFICATIONMESSAGE_H
