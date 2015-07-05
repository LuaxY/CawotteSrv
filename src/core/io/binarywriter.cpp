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
#include "binaryreader.h"
#include <stdexcept>

BinaryWriter::BinaryWriter(std::vector<char>& buffer) :
    _index(0),
    _buffer(buffer)
{
}

unsigned int BinaryWriter::index()
{
    return _index;
}

void BinaryWriter::setIndex(unsigned int index)
{
    _index = index;
}

void BinaryWriter::writeByte(char data)
{
    write(data);
}

void BinaryWriter::writeBytes(std::vector<char> data, bool writeSize)
{
    write(data, writeSize);
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

void BinaryWriter::writeVarInt(int data)
{

    std::vector<char> byteArray;

    if ((data >= 0) && (data <= MASK_01111111))
    {
        byteArray.push_back(static_cast<char>(data));
        writeBytes(byteArray);
        return;
    }

    int c = data;
    char byte;

    while (c != 0)
    {
        byte = static_cast<char>(c & MASK_01111111);
        c = static_cast<unsigned int>(c >> CHUNK_BIT_SIZE);

        if (c > 0)
        {
            byte = byte | MASK_10000000;
        }

        byteArray.push_back(byte);
    }

    writeBytes(byteArray);
}

void BinaryWriter::writeVarShort(short data)
{
    if ((data > SHORT_MAX_VALUE) || (data < SHORT_MIN_VALUE))
    {
        throw std::logic_error("Forbidden value");
    }

    std::vector<char> byteArray;

    if ((data >= 0) && (data <= MASK_01111111))
    {
        byteArray.push_back(static_cast<char>(data));
        writeBytes(byteArray);
        return;
    }

    int c = data & 0xFFFF;
    char byte;

    while (c != 0)
    {
        byte = static_cast<char>(c & MASK_01111111);
        c = static_cast<unsigned int>(c >> CHUNK_BIT_SIZE);

        if (c > 0)
        {
            byte = byte | MASK_10000000;
        }

        byteArray.push_back(byte);
    }

    writeBytes(byteArray);

}

void BinaryWriter::writeVarLong(double data)
{
    Int64 val = Int64::fromNumber(data);

    if (val.getHigh() == 0)
    {
        writeInt32(val.low);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            writeByte(static_cast<char>(val.low & MASK_01111111));
            val.low = static_cast<unsigned int>(val.low >> 7);
        }

        if ((val.getHigh() & (268435455 << 3)) == 0)
        {
            writeByte(static_cast<char>(val.getHigh() << 4));
        }
        else
        {
            writeByte(static_cast<char>((((val.getHigh() << 4) | val.low) & MASK_01111111) | MASK_10000000));
            writeInt32(static_cast<unsigned int>(val.getHigh() >> 3));
        }
    }
}

void BinaryWriter::writeInt32(unsigned int data)
{
    while (true)
    {
        if (data < MASK_10000000)
        {
            writeByte(static_cast<char>(data));
            return;
        }

        writeByte(static_cast<char>((data & MASK_01111111) | MASK_10000000));
        data = static_cast<unsigned int>(data >> 7);
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
void BinaryWriter::write(const std::vector<T>& data, bool writeSize)
{
    const char* bytes = reinterpret_cast<const char*>(&data[0]);
    unsigned short size = static_cast<unsigned short>(data.size());

    if (writeSize)
    {
        writeUShort(size);
    }

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