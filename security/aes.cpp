#include "aes.h"

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdexcept>
#include <vector>

#include "trpc/util/log/logging.h"

namespace trpc {
  namespace app {


Aes::Aes(const std::string& key, const std::string& iv)
    : key(key), iv(iv) {
    if (key.size() != 16 && key.size() != 24 && key.size() != 32) {

        TRPC_FMT_ERROR("key format error, key size must be 128, 192, or 256 bits, key={}", key);
        throw std::invalid_argument("Key size must be 128, 192, or 256 bits");

    }
    if (!iv.empty() && iv.size() != AES_BLOCK_SIZE) {
        TRPC_FMT_ERROR("iv format error, iv size must be empty or 16 bytes, key={}", iv);
        throw std::invalid_argument("iv size must be empty or 16 bytes");
    }
}

std::string Aes::encryptECB(const std::string& plaintext) {
    return cipher(plaintext, AES_ENCRYPT, Mode::ECB);
}

std::string Aes::decryptECB(const std::string& ciphertext) {
    return cipher(ciphertext, AES_DECRYPT, Mode::ECB);
}

std::string Aes::encryptCBC(const std::string& plaintext) {
    return cipher(plaintext, AES_ENCRYPT, Mode::CBC);
}

std::string Aes::decryptCBC(const std::string& ciphertext) {
    return cipher(ciphertext, AES_DECRYPT, Mode::CBC);
}

std::string Aes::cipher(const std::string& input, int operation, int mode) {
    std::vector<unsigned char> keyvec(key.begin(), key.end());
    std::vector<unsigned char> ivvec;
    if (!iv.empty()) {
        ivvec.assign(iv.begin(), iv.end());
    }

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) throw std::runtime_error("Failed to create cipher context");

    const EVP_CIPHER* cipher;
    if (mode == Mode::ECB) {
        cipher = EVP_aes_128_ecb();
    } else if (mode == Mode::CBC) {
        cipher = EVP_aes_128_cbc();
    } else {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Unsupported mode");
    }

    if (EVP_CipherInit_ex(ctx, cipher, nullptr, keyvec.data(), iv.empty() ? nullptr : ivvec.data(), operation) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Cipher initialization failed");
    }

    std::vector<unsigned char> output(input.size() + AES_BLOCK_SIZE);
    int output_len = 0;
    int len;

    if (EVP_CipherUpdate(ctx, output.data(), &len, reinterpret_cast<const unsigned char*>(input.data()), input.size()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Cipher update failed");
    }
    output_len = len;

    if (EVP_CipherFinal_ex(ctx, output.data() + len, &len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Cipher finalization failed");
    }
    output_len += len;

    EVP_CIPHER_CTX_free(ctx);
    output.resize(output_len);
    return std::string(output.begin(), output.end());
}

}
}
