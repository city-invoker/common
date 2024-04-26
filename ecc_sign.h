// copyright skylanwei 2024-04-22
#pragma once

#include <openssl/evp.h>
#include <string>

namespace trpc {
  namespace app {

class EccSign {
private:
  static std::string private_key_pem;
  static std::string public_key_pem;
  static EVP_PKEY* private_key;
  static EVP_PKEY* public_key;

public:
  static void Init();
  static void LoadPrivateKey(const std::string& private_key_pem);
  static void LoadPublicKey(const std::string& public_key_pem);
  static std::string Signature(const std::string& message);
  static bool Verify(const std::string& message, const std::string& sign);
};


}
}

