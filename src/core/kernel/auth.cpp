//
// auth.cpp
// CawotteSrv
//
// Created by Luax on 7/1/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "auth.h"
#include "core/utils/generate.h"

#include <iostream>
#include <fstream>

#include "dofus/network/messages/connection/helloconnectmessage.h"
#include "dofus/network/messages/handshake/protocolrequiredmessage.h"
#include "dofus/network/messages/connection/identificationmessage.h"
#include "dofus/network/messages/connection/identificationsuccessmessage.h"
#include "dofus/network/messages/connection/serverlistmessage.h"
#include "dofus/network/enums/serverstatusenum.h"

#include "dofus/frames/connection/authentificationframe.h"

#define SIZE_OF_SALT 32

void Auth::init(std::string ipToBind, ushort portToListen)
{
    Server::init(ipToBind, portToListen);

    std::ifstream keyFile("key/dofus.key", std::ios::binary);
    std::copy(std::istreambuf_iterator<char>(keyFile), std::istreambuf_iterator<char>(), std::back_inserter(_key));
}

void Auth::onNewConnection(Client& client)
{
    std::string salt = Generate::salt(SIZE_OF_SALT);

    HelloConnectMessage hcm;
    hcm.initHelloConnectMessage(salt, _key);
    client.send(hcm);

    ProtocolRequiredMessage prm;
    prm.initProtocolRequiredMessage(1645, 1645);
    client.send(prm);
}

bool Auth::onNewPacket(Client& client, Packet& packet)
{
    // TODO: dispatch packet

    /**
     * foreach frame in framesList
     * {
     *    if frame.process(client, packet)
     *        break;
     * }
     **/

    AuthentificationFrame af;
    af.registerMessages();

    if (af.process(client, packet))
    {
        return true;
    }

    /*if (packet.id() == 4)
    {
        try
        {
            IdentificationMessage im;
            BinaryReader reader(packet.data());
            im.deserialize(reader);

            //std::cout << "IdentificationMessage " << im.lang << std::endl << std::flush;

            IdentificationSuccessMessage ism;
            ism.initIdentificationSuccessMessage("Luax", "Luax", 1, 1, true, "Qui est le plus fort ?");
            client.send(ism);

            GameServerInformations jiva;
            jiva.initGameServerInformations(1, ServerStatusEnum::ONLINE, 0, true, 1);
            std::vector<GameServerInformations> serversList;
            serversList.push_back(jiva);

            ServerListMessage slm;
            slm.initServerListMessage(serversList, 0, true);
            client.send(slm);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl << std::flush;
        }

        return true;
    }*/

    return false;
}