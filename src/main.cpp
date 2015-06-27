#include "net/server.h"

using Poco::Thread;

int main(int argc, char** argv)
{
    Net::Server server("0.0.0.0", 5555);

    Thread serverThread;
    serverThread.start(server);
    serverThread.join();

    return 0;
}
