//
// identificationsuccessmessage.h
// CawotteSrv
//
// Created by Luax on 7/5/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_IDENTIFICATIONSUCCESSMESSAGE_H
#define CAWOTTESRV_IDENTIFICATIONSUCCESSMESSAGE_H

#include "dofus/network/messages/imessage.h"
#include "dofus/network/types/version/versionextended.h"

class IdentificationSuccessMessage : public IMessage
{
public:
    void initIdentificationSuccessMessage(
        std::string _login = "",
        std::string _nickname = "",
        unsigned int _accountId = 0,
        unsigned int _communityId = 0,
        bool _hasRights = false,
        std::string _secretQuestion = "",
        double _accountCreation = 0,
        double _subscriptionElapsedDuration = 0,
        double _subscriptionEndDate = 0,
        bool _wasAlreadyConnected = 0
    );

    unsigned short getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int id = 22;

    /* VARIABLES */

    std::string login;
    std::string nickname;
    unsigned int accountId;
    unsigned int communityId;
    bool hasRights;
    std::string secretQuestion;
    double accountCreation;
    double subscriptionElapsedDuration;
    double subscriptionEndDate;
    bool wasAlreadyConnected;
};


#endif // CAWOTTESRV_IDENTIFICATIONSUCCESSMESSAGE_H
