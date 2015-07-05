//
// gameserverinformations.h
// CawotteSrv
//
// Created by Luax on 7/5/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_GAMESERVERINFORMATIONS_H
#define CAWOTTESRV_GAMESERVERINFORMATIONS_H

#include "dofus/network/types/itype.h"

class GameServerInformations : public IType
{
public:
    void initGameServerInformations(
        unsigned int _id = 0,
        unsigned int _status = 1,
        unsigned int _completion = 0,
        bool _isSelectable = true,
        unsigned int _characterCount = 0,
        double _date = 0
    );
    unsigned short getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int __id = 25;

    /* VARIABLES */

    unsigned int id;
    unsigned int status;
    unsigned int completion;
    bool isSelectable;
    unsigned int characterCount;
    double date;
};


#endif // CAWOTTESRV_GAMESERVERINFORMATIONS_H
