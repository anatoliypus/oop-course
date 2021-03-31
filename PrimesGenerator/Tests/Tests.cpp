#include "../../catch2/catch.hpp"
#include "../PrimesGenerator/PrimesGenerator.h"

TEST_CASE("Testing checking is prime function")
{
    REQUIRE(IsPrime(167));
    REQUIRE(IsPrime(3301));
    REQUIRE(IsPrime(2));
    REQUIRE(!IsPrime(625));
    REQUIRE(!IsPrime(1));
    REQUIRE(!IsPrime(0));
}

TEST_CASE("Testing set generating function")
{
    REQUIRE(GeneratePrimeNumbersSet(2).size() == 1);
    REQUIRE(GeneratePrimeNumbersSet(10).size() == 4);
    REQUIRE(GeneratePrimeNumbersSet(100000000).size() == 5761455);
}
