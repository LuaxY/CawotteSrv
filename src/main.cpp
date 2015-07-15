#include "core/kernel/kernel.h"
#include <iostream>

void displayHelp(char* processName);

int main(int argc, char** argv)
{
    std::cout << "[Cawotte Server "
        << CawotteSrv_MAJOR << "."
        << CawotteSrv_MINOR << "."
        << CawotteSrv_PATCH
        << "] Starting..." << std::endl;

    char* configFile;

    for (int i = 1; i < argc; ++i)
    {
        if      (strcmp(argv[i], "-h") == 0) { displayHelp(argv[0]);     return 0; }
        else if (strcmp(argv[i], "-c") == 0) { configFile = argv[i + 1]; continue; }
    }

    Kernel kernel = Kernel::create();
    kernel.init();

    return 0;
}

void displayHelp(char* processName)
{
    std::cout << "Usage: " << processName << " [-c config/cawotte.ini]" << std::endl;
    std::cout << "  -c      use specific config file" << std::endl;
    std::cout << "  -h      show help" << std::endl;
}