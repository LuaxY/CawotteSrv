#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <memory>
#include <vector>

#include <Poco/ThreadPool.h>
#include <Poco/Runnable.h>
#include <Poco/Net/ServerSocket.h>

#include "client.h"

using Poco::ThreadPool;
using Poco::Runnable;
using Poco::Net::ServerSocket;
using Poco::Net::StreamSocket;
using Poco::Net::SocketAddress;

class Server : public Runnable
{
public:
    Server(std::string ipToBind, unsigned short portToListen);
    void run();

private:
    std::string _ipToBind;
    unsigned short _portToBind;
    std::unique_ptr<ServerSocket> _serverSocket;
    ThreadPool _clientThreadPool;
    std::vector<std::shared_ptr<Client>> _clientList;
};

#endif // SERVER_H
