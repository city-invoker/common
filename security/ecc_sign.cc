#include "ecc_sign.h"

#include <openssl/evp.h>
#include <openssl/pem.h>
#include <string>
#include <vector>

namespace trpc {
namespace app { 

EccSign::EccSign() {
  //TODO:load key from config
  private_key_pem = R"(
        -----BEGIN EC PRIVATE KEY-----
        MHcCAQEEIMiI8EHSGbKKv9fKG/Fe+qdAHe+E9vbGlbxkWDkatjG0oAoGCCqGSM49
        AwEHoUQDQgAE7rzrr43IA/FL8VazICb/4PenVf/HHfz5DDE7vsmx79u5Fr9Vau4+
        0YfD+dmIW1f1dnOvaKlFklm6DWeJmCrTgw==
        -----END EC PRIVATE KEY-----
  )";
  LoadPrivateKey(private_key_pem);
  public_key_pem = R"(
        -----BEGIN PUBLIC KEY-----
        MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAE7rzrr43IA/FL8VazICb/4PenVf/H
        Hfz5DDE7vsmx79u5Fr9Vau4+0YfD+dmIW1f1dnOvaKlFklm6DWeJmCrTgw==
        -----END PUBLIC KEY-----
  )";
  LoadPublicKey(public_key_pem);
  return;
}

EccSign::EccSign(const std::string&& private_key_pem, const std::string& public_key_pem): private_key_pem(private_key_pem), public_key_pem(public_key_pem) {

  LoadPrivateKey(private_key_pem);
  LoadPublicKey(public_key_pem);

}

void EccSign::LoadPrivateKey(const std::string& private_key_pem) {

  BIO* bio = BIO_new_mem_buf(private_key_pem.data(), private_key_pem.size());
  private_key = PEM_read_bio_PrivateKey(bio, nullptr, nullptr, nullptr);
  BIO_free(bio);
  return;
}

void EccSign::LoadPublicKey(const std::string& public_key_pem) {

  BIO* bio = BIO_new_mem_buf(public_key_pem.data(), public_key_pem.size());
  public_key = PEM_read_bio_PUBKEY(bio, nullptr, nullptr, nullptr);
  BIO_free(bio);

  return;
}

std::string EccSign::Signature(const std::string& message) {

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    bool b = EVP_DigestSignInit(ctx, nullptr, EVP_sha256(), nullptr, private_key);
    b = EVP_DigestSignUpdate(ctx, message.c_str(), message.length());

    size_t siglen;
    b = EVP_DigestSignFinal(ctx, nullptr, &siglen);

    std::vector<unsigned char> signature(siglen);
    b = EVP_DigestSignFinal(ctx, signature.data(), &siglen);
    EVP_MD_CTX_free(ctx);

    std::string s(signature.begin(), signature.end());
    return s;

}


bool EccSign::Verify(const std::string& message, const std::string& signature) {

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    bool b = EVP_DigestVerifyInit(ctx, nullptr, EVP_sha256(), nullptr, public_key);
    b = EVP_DigestVerifyUpdate(ctx, message.c_str(), message.length());
    int result = EVP_DigestVerifyFinal(ctx, reinterpret_cast<const unsigned char*>(signature.c_str()), signature.length());
    EVP_MD_CTX_free(ctx);

    return result == 1 ? true : false;
}



}
}
