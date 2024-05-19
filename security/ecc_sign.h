// copyright skylanwei 2024-04-22

#ifndef TRPC_COMMON_SECURITY_ECC_SIGN_H_
#define TRPC_COMMON_SECURITY_ECC_SIGN_H_

#include <openssl/evp.h>
#include <string>

namespace trpc {
  namespace app {

class EccSign {
private:
  std::string private_key_pem;
  std::string public_key_pem;
  EVP_PKEY* private_key;
  EVP_PKEY* public_key;

public:
  EccSign();
  EccSign(const std::string&& private_key_pem, const std::string& public_key_pem);
  
  void LoadPrivateKey(const std::string& private_key_pem);
  void LoadPublicKey(const std::string& public_key_pem);
  std::string Signature(const std::string& message);
  bool Verify(const std::string& message, const std::string& sign);
};


}
}

#endif // TRPC_COMMON_SECURITY_ECC_SIGN_H_
