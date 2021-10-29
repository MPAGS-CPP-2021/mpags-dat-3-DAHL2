#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
  public:
    explicit CaesarCipher(const std::size_t cipherKey);
    explicit CaesarCipher(const std::string cipherKey);
    std::size_t key_{0};
    static bool validateKey(const std::string testKey);
};

#endif    // MPAGSCIPHER_CAESARCIPHER_HPP
