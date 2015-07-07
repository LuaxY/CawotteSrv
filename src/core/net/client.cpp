//
// client.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "client.h"
#include "server.h"
#include "hexdump/hexdump.h"

#include <iostream>

#include <Poco/Thread.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/Net/NetException.h>

#define SIZE_OF_BUFFER 2048

using Poco::Thread;
using Poco::Net::SocketStream;
using Poco::Net::NetException;

Client::Client(Server& server, StreamSocket clientSocket) :
    _server(server),
    _clientSocket(clientSocket)
{
}

void Client::run()
{
    _server.onNewConnection(*this);
    isRunning = true;

    std::cout << "SEND DATA..." << std::endl << std::flush;

    while (isRunning)
    {
        receive();
        //Thread::sleep(1000);
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

void Client::receive()
{
    try
    {
        char tmpBuffer[SIZE_OF_BUFFER + 1];
        int size = _clientSocket.receiveBytes(tmpBuffer, SIZE_OF_BUFFER);

        if (size == 0)
        {
            close();
        }
        else
        {
            Packet packet;
            std::vector<char> buffer(tmpBuffer, tmpBuffer + size);

            while (packet.deserialize(buffer))
            {
                if (!_server.onNewPacket(*this, packet))
                {
                    std::cout << "receive packet id " << packet.id() << ", " << packet.length() << " bytes" << std::endl << std::flush;
                    hexdump(tmpBuffer, static_cast<uint>(size));
                }
            }
        }
    }
    catch (NetException& e)
    {
        std::cout << "[" << e.className() << "] " << e.what() << std::endl << std::flush;
    }
}

void Client::close()
{
    // TODO: log disconnection
    //_clientSocket.shutdown();
    _clientSocket.close();
    isRunning = false;
}