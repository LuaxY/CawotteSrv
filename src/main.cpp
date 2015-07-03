#include "core/kernel/kernel.h"
#include <iostream>

/*
#include <Poco/Crypto/RSAKey.h>
#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>
*/

/*
#include <Poco/Base64Decoder.h>
#include <Poco/StreamCopier.h>
#include <fstream>
*/

/*
using Poco::Crypto::RSAKey;
using Poco::Crypto::Cipher;
using Poco::Crypto::CipherFactory;
*/

/*
using Poco::Base64Decoder;
using Poco::StreamCopier;
*/

int main(int argc, char** argv)
{
    std::cout << "[Cawotte Server "
        << CawotteSrv_MAJOR << "."
        << CawotteSrv_MINOR << "."
        << CawotteSrv_PATCH
        << "] Starting..." << std::endl;

    /*
    RSAKey key(RSAKey::KL_512, RSAKey::EXP_SMALL);
    //key.save("key.pub", "key.priv", "dev");

    CipherFactory& cipherFactory = CipherFactory::defaultFactory();
    Cipher* cipher = cipherFactory.createCipher(key);

    std::string encrypted = cipher->encryptString("test", Cipher::ENC_BASE64);
    std::cout << encrypted << std::endl;
    */

    /*
    std::ifstream input("/home/dev/scratch/CawotteSrv/key/key.tmp");
    std::ofstream output("/home/dev/scratch/CawotteSrv/key/key", std::ios::binary);

    Base64Decoder decoder(input);
    StreamCopier::copyStream(decoder, output);
    */

    Kernel kernel = Kernel::create();
    kernel.init();

    return 0;
}
