#include "net/server.h"

#include <Poco/Thread.h>

using Poco::Thread;

int main(int argc, char** argv)
{
    Server server("127.0.0.1", 5555);

    Thread serverThread;
    serverThread.start(server);
    serverThread.join();

    return 0;
}
