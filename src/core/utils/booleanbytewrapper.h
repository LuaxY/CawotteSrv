//
// booleanbytewrapper.h
// CawotteSrv
//
// Created by Luax on 6/30/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_BOOLEANBYTEWRAPPER_H
#define CAWOTTESRV_BOOLEANBYTEWRAPPER_H

#include <stdexcept>

namespace Core {
namespace Utils {

class BooleanByteWrapper
{
public:
    static char setFlag(char flag, char offset, bool value);
    static char setFlag(int flag, char offset, bool value);
    static bool getFlag(char flag, char offset);
};

}} // Core::Utils


#endif //CAWOTTESRV_BOOLEANBYTEWRAPPER_H
