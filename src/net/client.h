//
// client.h
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_CLIENT_H
#define CAWOTTESRV_CLIENT_H

#include "packet.h"
#include <memory>

#include <Poco/Runnable.h>
#include <Poco/Net/StreamSocket.h>

using Poco::Runnable;
using Poco::Net::StreamSocket;

namespace Net {

class Client : public Runnable
{
public:
    Client(StreamSocket clientSocket);
    void run();
    void send(Packet packet);

private:
    StreamSocket _clientSocket;
};

} // Net

#endif // CAWOTTESRV_CLIENT_H
