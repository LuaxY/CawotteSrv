//
// byteorder.h
// CawotteSrv
//
// Created by Luax on 7/17/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_BYTEORDER_H
#define CAWOTTESRV_BYTEORDER_H

#include "types.h"

class ByteOrder
{
public:
    static ushort swap(ushort value);
    static short  swap(short value);
    static uint   swap(uint value);
    static int    swap(int value);
    static ulong  swap(ulong value);
    static long   swap(long value);
};


#endif // CAWOTTESRV_BYTEORDER_H
