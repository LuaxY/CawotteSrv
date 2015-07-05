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
#include "hexdump/hexdump.h"

#include <Poco/Net/SocketStream.h>
#include <Poco/Net/NetException.h>

#include "dofus/network/messages/connection/helloconnectmessage.h"
#include "dofus/network/messages/handshake/protocolrequiredmessage.h"
#include "dofus/network/messages/connection/identificationmessage.h"
#include "dofus/network/messages/connection/identificationsuccessmessage.h"
#include "dofus/network/messages/connection/serverlistmessage.h"
#include "dofus/network/types/connection/gameserverinformations.h"

#define SIZE_OF_SALT 32
#define SIZE_OF_BUFFER 2048

using Poco::Thread;
using Poco::Net::SocketStream;
using Poco::FIFOBuffer;
using Poco::Net::NetException;

Client::Client(StreamSocket clientSocket) :
    _clientSocket(clientSocket)
{
}

void Client::run()
{
    isRunning = true;

    std::ifstream keyFile("key/dofus.key", std::ios::binary);
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
                // TODO: dispatch packet

                if (packet.id() == 4)
                {
                    try
                    {
                        IdentificationMessage im;
                        BinaryReader reader(packet.data());
                        im.deserialize(reader);

                        std::cout << "IdentificationMessage " << im.lang << std::endl << std::flush;

                        IdentificationSuccessMessage ism;
                        ism.initIdentificationSuccessMessage("Luax", "Luax", 1, 1, true, "Qui est le plus fort ?");
                        send(ism);

                        GameServerInformations jiva;
                        jiva.initGameServerInformations(1, 1, 0, true, 1);
                        std::vector<GameServerInformations> serversList;
                        serversList.push_back(jiva);

                        ServerListMessage slm;
                        slm.initServerListMessage(serversList, 0, true);
                        send(slm);
                    }
                    catch (std::exception& e)
                    {
                        std::cout << e.what() << std::endl << std::flush;
                    }
                }
                else
                {
                    std::cout << "receive packet id " << packet.id() << ", " << packet.length() << " bytes" << std::endl << std::flush;
                    hexdump(tmpBuffer, static_cast<unsigned int>(size));
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