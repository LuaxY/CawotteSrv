#include "client.h"
#include <iostream>

#include <Poco/Net/SocketStream.h>
#include <Poco/Thread.h>

using Poco::Thread;
using Poco::Net::SocketStream;

Client::Client(StreamSocket clientSocket) :
    _clientSocket(clientSocket)
{
}

void Client::run()
{
    // Init client here (send hello message)

    std::cout << "SEND DATA..." << std::endl << std::flush;;

    for (;;)
    {
        _clientSocket.sendBytes("abc", 3);
        Thread::sleep(1000);
    }
}
