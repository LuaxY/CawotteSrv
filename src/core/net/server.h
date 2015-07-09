//
// server.h
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_SERVER_H
#define CAWOTTESRV_SERVER_H

#include <string>
#include <memory>
#include <vector>

#include <Poco/Thread.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketReactor.h>
#include <Poco/Net/SocketAcceptor.h>

#include "client.h"
#include "core/utils/types.h"
#include "core/utils/singleton.h"

using namespace Poco;
using namespace Poco::Net;

class Server
{
public:
    void init(std::string ipToBind, ushort portToListen);
    void run()
    {
        SocketAcceptor<Client> acceptor(*_serverSocket, _reactor);

        Thread thread;
        thread.start(_reactor);

        thread.join();
        _reactor.stop();
    }

private:
    std::string _ipToBind;
    ushort _portToBind;
    ServerSocket* _serverSocket;
    SocketReactor _reactor;
    bool _isRunning;
};

#endif // CAWOTTESRV_SERVER_H
