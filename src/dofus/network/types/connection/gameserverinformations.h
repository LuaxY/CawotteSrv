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
        uint _id = 0,
        uint _status = 1,
        uint _completion = 0,
        bool _isSelectable = true,
        uint _characterCount = 0,
        double _date = 0
    );
    ushort getId();
    std::string getName();
    void serialize(BinaryWriter& writer);
    void deserialize(BinaryReader& reader);

    static const int __id = 25;

    /* VARIABLES */

    uint id;
    uint status;
    uint completion;
    bool isSelectable;
    uint characterCount;
    double date;
};


#endif // CAWOTTESRV_GAMESERVERINFORMATIONS_H
