//
// binarywriter.h
// CawotteSrv
//
// Created by Alexandre Martin on 17/08/13.
// Copyright (c) 2013-2014 scalexm. All rights reserved.
//
// Modified by Luax on 6/29/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_BINARYWRITER_H
#define CAWOTTESRV_BINARYWRITER_H

#include <Poco/ByteOrder.h>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using Poco::ByteOrder;

class BinaryWriter
{
public:
    BinaryWriter(std::vector<char>& buffer);

    unsigned int index();
    void setIndex(unsigned int index);

    void writeByte(char data);
    void writeBytes(std::vector<char> data, bool writeSize = true);
    void writeShort(signed short data);
    void writeUShort(unsigned short data);
    void writeInt(signed int data);
    void writeUInt(unsigned int data);
    void writeLong(signed long data);
    void writeULong(unsigned long data);
    void writeDouble(double data);
    void writeUTF(const char *data);
    void writeUTF(std::string data);
    void writeUTFBytes(const char *data, size_t length);
    void writeBool(bool data);
    void writeVarInt(int data);
    void writeVarShort(short data);
    void writeVarLong(double data);
    void writeInt32(unsigned int data);


private:
    std::vector<char>& _buffer;
    unsigned int _index;

    template<class T>
    void write(const T& data);

    template<class T>
    void write(const std::vector<T>& data, bool writeSize = true);

    const int INT_SIZE = 32;
    const int SHORT_SIZE = 16;
    const int SHORT_MIN_VALUE = -32768;
    const int SHORT_MAX_VALUE = 32767;
    const int UNGISNED_SHORT_MAX_VALUE = 65536;
    const int CHUNK_BIT_SIZE = 7;
    const int MAX_ENCODING_LENGTH = std::ceil(INT_SIZE / CHUNK_BIT_SIZE);
    const unsigned char MASK_10000000 = 128;
    const unsigned char MASK_01111111 = 127;
};

#endif // CAWOTTESRV_BINARYWRITER_H
