#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CipherMode.hpp"
#include "ProcessCommandLine.hpp"

TEST_CASE("Help request recognised", "[argument]")
{
    // _ placeholder since vector will contain command itself when run from command line
    const std::vector<std::string> help_h{"_", "-h"};
    const std::vector<std::string> help{"_", "--help"};
    ProgramSettings helpTest_h{};
    ProgramSettings helpTest{};
    const bool success_h{processCommandLine(help_h, helpTest_h)};
    const bool success{processCommandLine(help, helpTest)};
    REQUIRE(success_h);
    REQUIRE(helpTest_h.helpRequested);
    REQUIRE(success);
    REQUIRE(helpTest.helpRequested);
}

TEST_CASE("Version request recognised", "[argument]")
{
    const std::vector<std::string> version{"_", "--version"};
    ProgramSettings versionTest{};
    const bool success{processCommandLine(version, versionTest)};
    REQUIRE(success);
    REQUIRE(versionTest.versionRequested);
}

TEST_CASE("Input file recognised", "[argument]")
{
    const std::string testString{"test string"};
    const std::vector<std::string> input{"_", "-i", testString};
    ProgramSettings inputTest{};
    const bool success{processCommandLine(input, inputTest)};
    REQUIRE(success);
    REQUIRE(inputTest.inputFile == testString);
}

TEST_CASE("Output file recognised", "[argument]")
{
    const std::string testString{"test string"};
    const std::vector<std::string> output{"_", "-o", testString};
    ProgramSettings outputTest{};
    const bool success{processCommandLine(output, outputTest)};
    REQUIRE(success);
    REQUIRE(outputTest.outputFile == testString);
}

TEST_CASE("Key recognised", "[argument]")
{
    const std::string testString{"1test string1"};
    const std::vector<std::string> key{"_", "-k", testString};
    ProgramSettings keyTest{};
    const bool success{processCommandLine(key, keyTest)};
    REQUIRE(success);
    REQUIRE(keyTest.cipherKey == testString);
}

TEST_CASE("Input file, output file and key cannot be final character",
          "[validation]")
{
    const std::vector<std::string> inEnd{"_", "-i"};
    const std::vector<std::string> outEnd{"_", "-o"};
    const std::vector<std::string> keyEnd{"_", "-k"};
    ProgramSettings endTest{};
    const bool inSuccess{processCommandLine(inEnd, endTest)};
    const bool outSuccess{processCommandLine(outEnd, endTest)};
    const bool keySuccess{processCommandLine(keyEnd, endTest)};
    REQUIRE(!(inSuccess));
    REQUIRE(!(outSuccess));
    REQUIRE(!(keySuccess));
}

TEST_CASE("Encrypt recognised", "[argument]")
{
    const std::vector<std::string> encrypt{"_", "--encrypt"};
    ProgramSettings encryptTest{};
    const bool success{processCommandLine(encrypt, encryptTest)};
    REQUIRE(success);
    REQUIRE(encryptTest.cipherMode == CipherMode::Encrypt);
}

TEST_CASE("Decrypt recognised", "[argument]")
{
    const std::vector<std::string> decrypt{"_", "--decrypt"};
    ProgramSettings decryptTest{};
    const bool success{processCommandLine(decrypt, decryptTest)};
    REQUIRE(success);
    REQUIRE(decryptTest.cipherMode == CipherMode::Decrypt);
}

TEST_CASE("Unknown argument raises error", "[validation]")
{
    const std::vector<std::string> unknown{"_", "-n"};
    const std::vector<std::string> unknown_{"_", "_"};
    ProgramSettings unknownTest{};
    const bool success{processCommandLine(unknown, unknownTest)};
    const bool success_{processCommandLine(unknown_, unknownTest)};
    REQUIRE(!(success));
    REQUIRE(!(success_));
}