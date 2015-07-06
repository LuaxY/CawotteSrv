//
// binaryreader.h
// CawotteSrv
//
// Created by Alexandre Martin on 17/08/13.
// Copyright (c) 2013-2014 scalexm. All rights reserved.
//
// Modified by Luax on 6/29/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_BINARYREADER_H
#define CAWOTTESRV_BINARYREADER_H

#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <cmath>
#include "types/int64.h"
#include "types/uint64.h"
#include "core/utils/types.h"

class BinaryReader
{
public:
    BinaryReader(const char* buffer, int length);
    BinaryReader(const ByteArray buffer);
    BinaryReader(const std::deque<char> buffer);

    bool setIndex(uint index);
    uint index();
    int bytesAvailable();
    void reverseBytes(uint8_t* bytes, size_t count);
    void readBytes(uint8_t* bytes, size_t count);

    short readShort();
    ushort readUShort();
    int readInt();
    uint readUInt();
    long readLong();
    ulong readULong();
    char readByte();
    uchar readUByte();
    ByteArray readBytes();
    ByteArray readBytes(int length);
    std::string readUTF();
    std::string readUTFBytes(uint length);
    bool readBool();
    int readVarInt();
    uint readVarUhInt();
    short readVarShort();
    ushort readVarUhShort();
    double readVarLong();
    double readVarUhLong();
    Int64 readInt64();
    UInt64 readUInt64();

private:
    ByteArray _buffer;
    uint _index;

    template<class T>
    void read(T &val);

    template<class T>
    void read(std::vector<T> &val);

    const int INT_SIZE = 32;
    const int SHORT_SIZE = 16;
    const int SHORT_MIN_VALUE = -32768;
    const int SHORT_MAX_VALUE = 32767;
    const int UNGISNED_SHORT_MAX_VALUE = 65536;
    const int CHUNK_BIT_SIZE = 7;
    const int MAX_ENCODING_LENGTH = std::ceil(INT_SIZE / CHUNK_BIT_SIZE);
    const uchar MASK_10000000 = 128;
    const uchar MASK_01111111 = 127;
};

#endif // CAWOTTESRV_BINARYREADER_H
