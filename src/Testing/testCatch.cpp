#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Check basic operations
TEST_CASE("Addition works", "[maths]")
{
    REQUIRE(1 + 1 == 2);
}
TEST_CASE("Subraction works", "[maths]")
{
    REQUIRE(1 - 1 == 0);
}