#include "../../catch2/catch.hpp"
#include "../HTMLDecode/HTMLDecode.h"

TEST_CASE("Testing decode method with good tests")
{
    std::string str = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
    std::string expected = "Cat <says> \"Meow\". M&M`s";
    std::string result;
    Error err;
    HTMLDecode(str, result, err);
    REQUIRE(result == expected);

    str = "";
    expected = "";
    HTMLDecode(str, result, err);
    REQUIRE(result == expected);

    str = "Hi;";
    expected = "Hi;";
    HTMLDecode(str, result, err);
    REQUIRE(result == expected);
}

TEST_CASE("Testing decode method with bad tests")
{
    std::string str = "Cat &lt;says&gt; &quot;Meow&quot. M&amp;M&apos;s";
    std::string result;
    Error err;
    REQUIRE(!HTMLDecode(str, result, err));

    str = "&quot Hi";
    HTMLDecode(str, result, err);
    REQUIRE(!HTMLDecode(str, result, err));
}
