![Logo](http://i.imgur.com/2dscckl.png)

[![Build Status](https://travis-ci.org/LuaxY/CawotteSrv.svg?branch=master)](https://travis-ci.org/LuaxY/CawotteSrv) [![Issues](http://img.shields.io/github/issues/LuaxY/CawotteSrv.svg?style=flat)](https://github.com/twitch-irc/LuaxY/CawotteSrv)

CawotteSrv is Dofus 2 emulator developped in C++11  
[Kanban Board](http://dev.voidmx.net/boards/JHBQWdSQdkcC84qWD/cawottesrv)

[![Join the chat at https://gitter.im/LuaxY/CawotteSrv](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/LuaxY/CawotteSrv?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## Requirements

- Platform: Linux, Windows
- CMake ≥ 2.8
- GCC ≥ 4.8 (Linux)
- MSVC  12 (Windows)
- libevent >= 2.0

## Install

Run CMake and build server
```
cmake .
make
```

## Run

Launch server with configuration file and game mode
```
./CawotteSrv -c config/auth.ini -g auth
./CawotteSrv -c config/jiva.ini -g world
```

## Contributors

- LuaxY - https://github.com/LuaxY

## Thanks

- Xeo-Skr - https://github.com/Xeo-Skr
- scalexm - https://github.com/scalexm
- Alleos13 - https://github.com/Alleos13
- Many others

## Copyright

License: The MIT License (MIT)

Read file [LICENSE](LICENSE)

