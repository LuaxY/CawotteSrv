//
// config.h
// CawotteSrv
//
// Created by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_CONFIG_H
#define CAWOTTESRV_CONFIG_H

#include "core/utils/singleton.h"
#include <string>
#include <map>
#include <memory>
#include "inih/INIReader.h"

class Config : public Singleton<Config>
{
public:
    Config() { }
    void init(std::string filename);

    bool getBool(std::string key, bool defaultValue);
    double getDouble(std::string key, double defaultValue);
    int getInt(std::string key, int defaultValue);
    std::string getString(std::string key, std::string defaultValue);

private:
    std::unique_ptr<INIReader> reader;
    std::map<std::string, std::string> parseKey(std::string key);
};

#endif //CAWOTTESRV_CONFIG_H
