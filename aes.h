// copyright skylanwei 2024-05-19
#pragma once

#include <string>

namespace trpc {
  namespace app {

class Aes {

public:
    enum Mode {
      ECB = 0,
      CBC = 1,
    };

    Aes(const std::string& key, const std::string& iv = "");

    std::string encryptECB(const std::string& plaintext);
    std::string decryptECB(const std::string& ciphertext);
    std::string encryptCBC(const std::string& plaintext);
    std::string decryptCBC(const std::string& ciphertext);

private:
    std::string key;
    std::string iv;

    std::string cipher(const std::string& input, int operation, int mode);
};

}
}
