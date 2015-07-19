![Logo](http://i.imgur.com/2dscckl.png)

[![Build Status](https://travis-ci.org/LuaxY/CawotteSrv.svg?branch=master)](https://travis-ci.org/LuaxY/CawotteSrv) [![Issues](http://img.shields.io/github/issues/LuaxY/CawotteSrv.svg?style=flat)](https://github.com/twitch-irc/LuaxY/CawotteSrv)

CawotteSrv is Dofus 2 emulator developped in C++11  
[Kanban Board](http://dev.voidmx.net/boards/JHBQWdSQdkcC84qWD/cawottesrv)

## Install ![Icon](http://i.imgur.com/k3FhNf0.png)

[![Join the chat at https://gitter.im/LuaxY/CawotteSrv](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/LuaxY/CawotteSrv?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Dependencies:

- gcc/g++ >= 4.8
- cmake >= 2.8
- libevent >= 2.0-5
- libevent-dev

Run CMake and build server
```
cmake .
make
```

## Run ![Icon](http://i.imgur.com/avaUYAc.png)

Launch server with configuration file and game mode
```
./CawotteSrv -c config/auth.ini -g auth
./CawotteSrv -c config/jiva.ini -g world
```

## Contributors ![Icon](http://i.imgur.com/gaHjnk3.png)

- LuaxY - https://github.com/LuaxY

## Thanks ![Icon](http://i.imgur.com/QUGkKoc.png)

- Xeo-Skr - https://github.com/Xeo-Skr
- scalexm - https://github.com/scalexm
- Alleos13 - https://github.com/Alleos13
- Many others

## License ![Icon](http://i.imgur.com/rOOuzf4.png)

The MIT License (MIT)

Copyright (c) 2015 CawotteSrv

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
