//
// binaryreader.cpp
// CawotteSrv
//
// Created by Alexandre Martin on 17/08/13.
// Copyright (c) 2013-2014 scalexm. All rights reserved.
//
// Modified by Luax on 6/29/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "binaryreader.h"

BinaryReader::BinaryReader(const char* buffer, int length) :
    _buffer(buffer, buffer + length),
    _index(0)
{
}

BinaryReader::BinaryReader(const std::vector<char> buffer) :
    _buffer(buffer),
    _index(0)
{
}

BinaryReader::BinaryReader(const std::deque<char> buffer) :
    _index(0)
{
    _buffer.reserve(buffer.size());
    std::copy(buffer.begin(), buffer.end(), std::back_inserter(_buffer));
}

bool BinaryReader::setIndex(unsigned int index)
{
    if (index <= _buffer.size())
    {
        _index = index;
        return true;
    }

    return false;
}

unsigned int BinaryReader::index()
{
    return _index;
}

int BinaryReader::bytesAvailable()
{
    return static_cast<int>(_buffer.size() - _index);
}

void BinaryReader::reverseBytes(uint8_t* bytes, size_t count)
{
    for (size_t lo = 0, hi = count - 1; hi > lo; ++lo, --hi)
    {
        auto temp = bytes[hi];
        bytes[hi] = bytes[lo];
        bytes[lo] = temp;
    }
}

void BinaryReader::readBytes(uint8_t* bytes, size_t count)
{
    memcpy(bytes, &_buffer[_index], count);
    _index += count;
}

signed short BinaryReader::readShort()
{
    signed short value = 0;
    read(value);
    return value;
}

unsigned short BinaryReader::readUShort()
{
    unsigned short value = 0;
    read(value);
    return value;
}

signed int BinaryReader::readInt()
{
    signed int value = 0;
    read(value);
    return value;
}

unsigned int BinaryReader::readUInt()
{
    unsigned int value = 0;
    read(value);
    return value;
}

signed long BinaryReader::readLong()
{
    signed int value = 0;
    read(value);
    return value;
}

unsigned long BinaryReader::readULong()
{
    unsigned int value = 0;
    read(value);
    return value;
}

char BinaryReader::readByte()
{
    char value = _buffer[_index];

    _index++;
    return value;
}

std::vector<char> BinaryReader::readBytes()
{
    int length = readUShort();

    std::vector<char> value;

    for (int i = 0; i < length; i++)
        value.push_back(_buffer[_index + i]);

    value.push_back(0);
    _index += length;
    return value;
}

std::vector<char> BinaryReader::readBytes(int length)
{
    std::vector<char> value;

    for (int i = 0; i < length; i++)
        value.push_back(_buffer[_index + i]);

    value.push_back(0);
    _index += length;
    return value;
}

std::string BinaryReader::readUTF()
{
    unsigned short len = readUShort();
    std::vector<char> data = readBytes(len);
    return std::string(data.begin(), data.end());
}

std::string BinaryReader::readUTFBytes(unsigned int length)
{
    std::vector<char> data = readBytes(length);
    return std::string(data.begin(), data.end());
}

bool BinaryReader::readBool()
{
    return readByte() == 1;
}

template<class T>
void BinaryReader::read(T &val)
{
    readBytes(reinterpret_cast<uint8_t*>(&val), sizeof(T));
    reverseBytes(reinterpret_cast<uint8_t*>(&val), sizeof(T));
}

template<class T>
void BinaryReader::read(std::vector<T> &val)
{
    uint16_t size;
    read(size);
    val.resize(size);
    readBytes(reinterpret_cast<uint8_t*>(&val[0]), size);
}