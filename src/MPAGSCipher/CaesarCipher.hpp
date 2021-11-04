#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "CipherMode.hpp"

#include <string>
#include <vector>

class CaesarCipher {
  public:
    explicit CaesarCipher(const std::size_t cipherKey);
    explicit CaesarCipher(const std::string cipherKey);

    std::string applyCipher(const std::string message,
                            const CipherMode cipherMode) const;

    static bool validateKey(const std::string testKey);

  private:
    const std::vector<char> alphabet_{
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const std::size_t alphabetSize_{alphabet_.size()};
    std::size_t key_{0};
};

#endif    // MPAGSCIPHER_CAESARCIPHER_HPP
