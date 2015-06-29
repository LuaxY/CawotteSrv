//
// binarywriter.cpp
// CawotteSrv
//
// Created by Alexandre Martin on 17/08/13.
// Copyright (c) 2013-2014 scalexm. All rights reserved.
//
// Modified by Luax on 6/29/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "binarywriter.h"

using Core::IO::BinaryWriter;

BinaryWriter::BinaryWriter(std::vector<char>& buffer) :
    _buffer(buffer)
{
}

unsigned int BinaryWriter::index()
{
    return _index;
}

void BinaryWriter::writeByte(char data)
{
    write(data);
}

void BinaryWriter::writeBytes(std::vector<char> data)
{
    write(data);
}

void BinaryWriter::writeShort(signed short data)
{
    data = ByteOrder::toBigEndian(data);
    write(data);
}

void BinaryWriter::writeUShort(unsigned short data)
{
    data = ByteOrder::toBigEndian(data);
    write(data);
}

void BinaryWriter::writeInt(signed int data)
{
    data = ByteOrder::toBigEndian(data);
    write(data);
}

void BinaryWriter::writeUInt(unsigned int data)
{
    data = ByteOrder::toBigEndian(data);
    write(data);
}

void BinaryWriter::writeLong(signed long data)
{
    data = ByteOrder::toBigEndian(data);
    write(data);
}

void BinaryWriter::writeULong(unsigned long data)
{
    data = ByteOrder::toBigEndian(data);
    write(data);
}

void BinaryWriter::writeDouble(double data)
{
    int* p = (int*)&data;
    int tmp = p[0];
    p[0] = ByteOrder::toBigEndian(p[1]);
    p[1] = ByteOrder::toBigEndian(tmp);

    write(data);
}

void BinaryWriter::writeUTF(const char* data)
{
    size_t length = strlen(data);
    writeUTFBytes(data, length);
}

void BinaryWriter::writeUTF(std::string data)
{
    std::vector<char> vec(data.begin(), data.end());
    write(vec);
}

void BinaryWriter::writeUTFBytes(const char* data, size_t length)
{
    std::string str(data, length);
    writeUTF(str);
}

void BinaryWriter::writeBool(bool data)
{
    if (data)
    {
        writeByte(1);
    }
    else
    {
        writeByte(0);
    }
}

template<class T>
void BinaryWriter::write(const T& data)
{
    const char* bytes = reinterpret_cast<const char*>(&data);
    unsigned short size = static_cast<unsigned short>(sizeof(T));

    if (bytes == nullptr || size == 0)
    {
        return;
    }

    if (_buffer.size() < _index + size)
    {
        _buffer.resize(_index + size);
    }

    memcpy(&_buffer[_index], bytes, size);
    _index += size;
}

template<class T>
void BinaryWriter::write(const std::vector<T>& data)
{
    const char* bytes = reinterpret_cast<const char*>(&data[0]);
    unsigned short size = static_cast<unsigned short>(data.size());

    write(size);

    if (bytes == nullptr || size == 0)
    {
        return;
    }

    if (_buffer.size() < _index + size)
    {
        _buffer.resize(_index + size);
    }

    memcpy(&_buffer[_index], bytes, size);
    _index += size;
}