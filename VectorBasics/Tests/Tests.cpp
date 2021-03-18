#include "../VectorBasics/VectorBasics.h"
#include <catch2/catch_amalgamated.hpp>

TEST_CASE("Testing with a basic vector")
{
    DoubleVector testVect { 2, 10, 4 };
    DoubleVector result { 4, 20, 8 };
    CHECK(GetProcessedVector(testVect) == result);
}

TEST_CASE("Testing with a double value")
{
    DoubleVector testVect { 2, 10.225, 4 };
    DoubleVector result { 4, 20.45, 8 };
    CHECK(GetProcessedVector(testVect) == result);
}

TEST_CASE("Testing with only one element")
{
    DoubleVector testVect { 2 };
    DoubleVector result { 4 };
    CHECK(GetProcessedVector(testVect) == result);
}
