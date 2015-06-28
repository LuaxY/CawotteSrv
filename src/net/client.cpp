//
// client.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "client.h"
#include <iostream>

#include <Poco/Net/SocketStream.h>
#include <Poco/Thread.h>

using Net::Client;
using Poco::Thread;
using Poco::Net::SocketStream;

Client::Client(StreamSocket clientSocket) :
    _clientSocket(clientSocket)
{
}

void Client::run()
{
    // Init client here (send hello message)

    IMessage message;
    Packet test(message); // TODO: create fake IMessage
    send(test);

    std::cout << "SEND DATA..." << std::endl << std::flush;;

    for (;;)
    {
        _clientSocket.sendBytes("abc", 3);
        Thread::sleep(1000);
    }
}

void Client::send(Packet packet)
{
    try
    {
        packet.serialize();
        std::vector<char> buffer = packet.getBuffer();
        _clientSocket.sendBytes(buffer.data(), buffer.size());
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}