//
// client.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "client.h"
#include "core/utils/generate.h"
#include <iostream>
#include <fstream>

#include <Poco/Net/SocketStream.h>
#include <Poco/Thread.h>

#include "dofus/network/messages/connection/helloconnectmessage.h"
#include "dofus/network/messages/handsake/protocolrequiredmessage.h"

#define SIZE_OF_SALT 32

using Poco::Thread;
using Poco::Net::SocketStream;

Client::Client(StreamSocket clientSocket) :
    _clientSocket(clientSocket)
{
}

void Client::run()
{
    // Init client here (send hello message)

    std::ifstream keyFile("/root/scratch/CawotteSrv/key/dofus.key", std::ios::binary);
    std::vector<char> key;
    std::copy(std::istreambuf_iterator<char>(keyFile), std::istreambuf_iterator<char>(), std::back_inserter(key));
    std::string salt = Generate::salt(SIZE_OF_SALT);

    HelloConnectMessage hcm;
    hcm.initHelloConnectMessage(salt, key);
    send(hcm);

    ProtocolRequiredMessage prm;
    prm.initProtocolRequiredMessage(1645, 1645);
    send(prm);

    std::cout << "SEND DATA..." << std::endl << std::flush;

    for (;;)
    {
        //_clientSocket.sendBytes("abc", 3);
        Thread::sleep(1000);
    }
}

void Client::send(IMessage& message)
{
    try
    {
        std::vector<char> buffer;
        Packet packet;

        packet.serialize(message, buffer);

        _clientSocket.sendBytes(buffer.data(), static_cast<int>(buffer.size()));
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}