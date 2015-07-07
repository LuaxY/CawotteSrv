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

#include <Poco/ThreadPool.h>
#include <Poco/Runnable.h>
#include <Poco/Net/ServerSocket.h>

#include "client.h"
#include "core/utils/types.h"

using Poco::ThreadPool;
using Poco::Runnable;
using Poco::Net::ServerSocket;
using Poco::Net::StreamSocket;
using Poco::Net::SocketAddress;

class Server : public Runnable
{
public:
    Server() : _clientThreadPool(1, 100) { }

    virtual void init(std::string ipToBind, ushort portToListen);
    void run();

    virtual void onNewConnection(Client& client) = 0;
    virtual bool onNewPacket(Client& client, Packet& packet) = 0;

private:
    std::string _ipToBind;
    ushort _portToBind;
    std::unique_ptr<ServerSocket> _serverSocket;
    ThreadPool _clientThreadPool;
    std::vector<std::shared_ptr<Client>> _clientList;
};

#endif // CAWOTTESRV_SERVER_H
