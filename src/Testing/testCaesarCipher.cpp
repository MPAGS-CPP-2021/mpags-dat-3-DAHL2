#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

TEST_CASE("Key must be positive integer", "[validation]")
{
    REQUIRE(CaesarCipher::validateKey("1234567890"));
    REQUIRE(!(CaesarCipher::validateKey("-1")));
    REQUIRE(!(CaesarCipher::validateKey("1.")));
}

TEST_CASE("Caesar cipher encrypts correctly", "[alphanumeric]")
{
    CaesarCipher cipher1(1);
    CaesarCipher cipher25(25);
    REQUIRE(cipher1.applyCipher("ZA", CipherMode::Encrypt) == "AB");
    REQUIRE(cipher25.applyCipher("ZA", CipherMode::Encrypt) == "YZ");
}

TEST_CASE("Caesar cipher decrypts correctly", "[alphanumeric]")
{
    CaesarCipher cipher1(1);
    CaesarCipher cipher25(25);
    REQUIRE(cipher1.applyCipher("ZA", CipherMode::Decrypt) == "YZ");
    REQUIRE(cipher25.applyCipher("ZA", CipherMode::Decrypt) == "AB");
}

TEST_CASE("Key is taken modulo alphabet size", "[maths]")
{
    // Assume we are still using latin alphabet (26 characters)
    // Must test via applyCipher, since key_ is hidden
    CaesarCipher cipherString("0");
    CaesarCipher cipherStringWrap("26");
    CaesarCipher cipherInt(0);
    CaesarCipher cipherIntWrap(26);
    REQUIRE(cipherString.applyCipher("ZA", CipherMode::Encrypt) == "ZA");
    REQUIRE(cipherStringWrap.applyCipher("ZA", CipherMode::Encrypt) == "ZA");
    REQUIRE(cipherInt.applyCipher("ZA", CipherMode::Encrypt) == "ZA");
    REQUIRE(cipherIntWrap.applyCipher("ZA", CipherMode::Encrypt) == "ZA");
}