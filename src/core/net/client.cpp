//
// client.cpp
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "client.h"
#include "server.h"
#include "core/kernel/kernel.h"
#include "hexdump/hexdump.h"

#include <iostream>

#include <Poco/Net/SocketStream.h>
#include <Poco/Net/NetException.h>
#include <Poco/NObserver.h>

#define SIZE_OF_BUFFER 2048

using Poco::NObserver;

Client::Client(Socket& clientSocket, GameMode* gameMode) :
    _clientSocket(clientSocket),
    _gameMode(gameMode)
{
    _gameMode->onNewClient(*this);
}

void Client::onReadable()
{
    try
    {
        char tmpBuffer[SIZE_OF_BUFFER + 1];
        int size = 1; // _clientSocket.receiveBytes(tmpBuffer, SIZE_OF_BUFFER);

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
                if (!_gameMode->onNewPacket(*this, packet))
                {
                    std::cout << "receive packet id " << packet.id() << ", " << packet.length() << " bytes" << std::endl << std::flush;
                    hexdump(tmpBuffer, static_cast<uint>(size));
                }
            }
        }
    }
    catch (Poco::Net::NetException& e)
    {
        std::cout << "[" << e.className() << "] " << e.what() << std::endl << std::flush;
    }
}

void Client::onWritable()
{

}

void Client::onShutdown()
{
    close();
}

void Client::send(IMessage& message)
{
    try
    {
        std::vector<char> buffer;
        Packet packet;

        packet.serialize(message, buffer);

        // _clientSocket.sendBytes(buffer.data(), static_cast<int>(buffer.size()));

        std::cout << "[" << toString() << "] [SND] " <<
            message.getName() << " (" << message.getId() << ")" << std::endl << std::flush;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Client::close()
{
    std::cout << "[" << toString() << "] client disconnected"  << std::endl << std::flush;
    _clientSocket.close();
}

std::string Client::toString()
{
    return _clientSocket.toString();
}