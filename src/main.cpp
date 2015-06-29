#include "core/net/server.h"
#include <iostream>

using Poco::Thread;

int main(int argc, char** argv)
{
    std::cout << "[Cawotte Server "
        << CawotteSrv_MAJOR << "."
        << CawotteSrv_MINOR << "."
        << CawotteSrv_PATCH
        << "] Starting..." << std::endl;

    Core::Net::Server server("0.0.0.0", 5555);

    Thread serverThread;
    serverThread.start(server);
    serverThread.join();

    return 0;
}
