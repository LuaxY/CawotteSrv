//
// binary64.h
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_BINARY64_H
#define CAWOTTESRV_BINARY64_H


class Binary64
{
public:
    Binary64(unsigned int _low = 0, unsigned int _high = 0);

    unsigned int div(unsigned int n);
    void mul(unsigned int n);
    void add(unsigned int n);
    void bitWiseNot();

    unsigned int low;

protected:
    unsigned int internalHigh;

    static const char CHAR_CODE_0 = '0';
    static const char CHAR_CODE_9 = '9';
    static const char CHAR_CODE_A = 'A';
    static const char CHAR_CODE_Z = 'Z';
};


#endif // CAWOTTESRV_BINARY64_H
