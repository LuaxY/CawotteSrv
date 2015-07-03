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

class BinaryReader
{
public:
    BinaryReader(const char* buffer, int length);
    BinaryReader(const std::vector<char> buffer);
    BinaryReader(const std::deque<char> buffer);

    bool setIndex(unsigned int index);
    unsigned int index();
    int bytesAvailable();
    void reverseBytes(uint8_t* bytes, size_t count);
    void readBytes(uint8_t* bytes, size_t count);

    signed short readShort();
    unsigned short readUShort();
    signed int readInt();
    unsigned int readUInt();
    signed long readLong();
    unsigned long readULong();
    char readByte();
    std::vector<char> readBytes();
    std::vector<char> readBytes(int length);
    std::string readUTF();
    std::string readUTFBytes(unsigned int length);
    bool readBool();

private:
    std::vector<char> _buffer;
    unsigned int _index;

    template<class T>
    void read(T &val);

    template<class T>
    void read(std::vector<T> &val);
};

#endif // CAWOTTESRV_BINARYREADER_H
