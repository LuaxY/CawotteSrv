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

using Poco::ByteOrder;

class BinaryWriter
{
public:
    BinaryWriter(std::vector<char>& buffer);

    unsigned int index();

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

private:
    std::vector<char>& _buffer;
    unsigned int _index;

    //void write(const char* bytes, size_t count);
    template<class T>
    void write(const T& data);

    template<class T>
    void write(const std::vector<T>& data, bool writeSize = true);

};

#endif // CAWOTTESRV_BINARYWRITER_H
