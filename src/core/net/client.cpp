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
#include <event2/buffer.h>

Client::Client(Socket* clientSocket, GameMode* gameMode, EventBase* eventBase) :
    _clientSocket(clientSocket),
    _gameMode(gameMode),
    _eventBase(eventBase)
{
    // create buffer event for client
    _bufferEvent = bufferevent_socket_new(_eventBase->getEventBase(), _clientSocket->getSockfd(), BEV_OPT_CLOSE_ON_FREE);

    // set callback functions
    bufferevent_setcb(_bufferEvent, &Client::onReadable, NULL, &Client::onEvent, this);

    // set buffer limit
    bufferevent_setwatermark(_bufferEvent, EV_READ, 0, SIZE_OF_BUFFER);

    // start buffer event
    bufferevent_enable(_bufferEvent, EV_READ | EV_WRITE);

    _gameMode->onNewClient(*this);
}

void Client::onReadable(struct bufferevent* bufferEvent, void* arg)
{
    Client* pThis = (Client*)arg;

    char tmpBuffer[SIZE_OF_BUFFER];
    struct evbuffer* bufferInput = bufferevent_get_input(bufferEvent);
    int size = evbuffer_remove(bufferInput, tmpBuffer, SIZE_OF_BUFFER);

    if (size > 0)
    {
        Packet packet;
        std::vector<char> buffer(tmpBuffer, tmpBuffer + size);

        while (packet.deserialize(buffer))
        {
            if (!pThis->_gameMode->onNewPacket(*pThis, packet))
            {
                std::cout << "receive packet id " << packet.id() << ", " << packet.length() << " bytes" << std::endl << std::flush;
                hexdump(tmpBuffer, static_cast<uint>(size));
            }
        }
    }
}

void Client::onEvent(struct bufferevent* bufferEvent, short eventType, void* arg)
{
    Client* pThis = (Client*)arg;

    if (eventType & BEV_EVENT_EOF)
    {
        // TODO: remove client in clients list vector
        pThis->close();

        std::cout << "[" << pThis->toString() << "] [EVENT] " <<
            "BEV_EVENT_EOF" << std::endl;
        return;
    }

    if (eventType & BEV_EVENT_ERROR)
    {
        std::cout << "[" << pThis->toString() << "] [EVENT] " <<
            "BEV_EVENT_ERROR" << std::endl;
        return;
    }

    if (eventType & BEV_EVENT_TIMEOUT)
    {
        std::cout << "[" << pThis->toString() << "] [EVENT] " <<
            "BEV_EVENT_TIMEOUT" << std::endl;
        return;
    }

    std::cout << "[" << pThis->toString() << "] [EVENT] " <<
        "UNKNOWN_EVENT: " << eventType << std::endl;
}

void Client::send(IMessage& message)
{
    try
    {
        std::vector<char> buffer;
        Packet packet;

        packet.serialize(message, buffer);

        bufferevent_write(_bufferEvent, buffer.data(), buffer.size());

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
    _clientSocket->close();
}

std::string Client::toString()
{
    return _clientSocket->toString();
}
