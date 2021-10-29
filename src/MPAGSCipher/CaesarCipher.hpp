#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

class CaesarCipher {
    unsigned long key_;

  public:
    CaesarCipher(const unsigned long cipherKey);
};

#endif    // MPAGSCIPHER_CAESARCIPHER_HPP
