//
// signleton.h
// CawotteSrv
//
// Created by Alexandre Martin on 29/07/13.
// Copyright (c) 2013-2014 scalexm. All rights reserved.
//
// Modified by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_SIGNLETON_H
#define CAWOTTESRV_SIGNLETON_H

#include <memory>
#include <cassert>

namespace Core {
namespace Utils {

template<class T>
class Singleton
{
protected:
    Singleton() = default;
    ~Singleton() = default;

public:
    template<class ... Args>
    static T& create(Args &&... args)
    {
        assert(!_singleton);
        _singleton.reset(new T{std::forward<Args>(args)...});
        return *_singleton;
    }

    static void kill()
    {
        _singleton.reset(nullptr);
    }

    static T& instance()
    {
        assert(_singleton);
        return *_singleton;
    }

private:
    static std::unique_ptr<T> _singleton;
};

template<class T>
std::unique_ptr<T> Singleton<T>::_singleton;

}} // Core::Utils

#endif //CAWOTTESRV_SIGNLETON_H
