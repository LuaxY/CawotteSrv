#ifndef CLIENT_H
#define CLIENT_H

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

private:
    StreamSocket _clientSocket;
};

} // Net

#endif // CLIENT_H
