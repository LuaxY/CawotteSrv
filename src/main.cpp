#include "core/kernel/kernel.h"
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "[Cawotte Server "
        << CawotteSrv_MAJOR << "."
        << CawotteSrv_MINOR << "."
        << CawotteSrv_PATCH
        << "] Starting..." << std::endl;

    Kernel kernel = Kernel::create();
    kernel.init();

    return 0;
}
