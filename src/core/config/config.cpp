//
// config.cpp
// CawotteSrv
//
// Created by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "config.h"
#include <sstream>

void Config::init(std::string filename)
{
    reader = std::unique_ptr<INIReader>(new INIReader(filename));

    if (reader->ParseError() < 0)
    {
        // this is not really exception safe...
        throw std::logic_error("unable to open configuration file");
    }
}

bool Config::getBool(std::string key, bool defaultValue)
{
    auto keys = parseKey(key);
    return reader->GetBoolean(keys["section"], keys["name"], defaultValue);
}

double Config::getDouble(std::string key, double defaultValue)
{
    auto keys = parseKey(key);
    return reader->GetReal(keys["section"], keys["name"], defaultValue);
}

int Config::getInt(std::string key, int defaultValue)
{
    auto keys = parseKey(key);
    return static_cast<int>(reader->GetInteger(keys["section"], keys["name"], defaultValue));
}

std::string Config::getString(std::string key, std::string defaultValue)
{
    auto keys = parseKey(key);
    return reader->Get(keys["section"], keys["name"], defaultValue);
}

std::map<std::string, std::string> Config::parseKey(std::string key)
{
    std::map<std::string, std::string> keys;
    std::istringstream keyStream(key);

    std::getline(keyStream, keys["section"], '.');
    std::getline(keyStream, keys["name"], '.');

    return keys;
}