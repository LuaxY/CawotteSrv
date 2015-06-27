#include "net/server.h"
#include <iostream>

using Poco::Thread;

int main(int argc, char** argv)
{
    std::cout << "[Cawotte Server] Starting..." << std::endl;

    Net::Server server("0.0.0.0", 5555);

    Thread serverThread;
    serverThread.start(server);
    serverThread.join();

    return 0;
}
