#include "Dictionary/Dictionary.h"
#include <../catch2/catch.hpp>

TEST_CASE("Testing lowercasing")
{
    std::string test = "aBcDeFg";
    std::string expected = "abcdefg";
    std::string result = StrToLowerCase(test);
    REQUIRE(result == expected);

    test = "";
    expected = "";
    result = StrToLowerCase(test);
    REQUIRE(result == expected);
}

TEST_CASE("Testing keys modifying")
{
    std::string test = "aBc";
    std::string expected = "[abc]";
    std::string result = ModifyKey(test);
    REQUIRE(result == expected);

    test = "";
    expected = "[]";
    result = ModifyKey(test);
    REQUIRE(result == expected);
}
