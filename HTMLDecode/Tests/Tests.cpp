#include "../../catch2/catch.hpp"
#include "../HTMLDecode/HTMLDecode.h"

TEST_CASE("Testing decode method")
{
    std::string str = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
    std::string expected = "Cat <says> \"Meow\". M&M`s";
    REQUIRE(HTMLDecode(str) == expected);

    str = "";
    expected = "";
    REQUIRE(HTMLDecode(str) == expected);

    str = "Hi;";
    expected = "Hi;";
    REQUIRE(HTMLDecode(str) == expected);

    str = "&quott;Hello world&quot;";
    expected = "&quott;Hello world\"";
    REQUIRE(HTMLDecode(str) == expected);

    str = "&quot";
    expected = "&quot";
    REQUIRE(HTMLDecode(str) == expected);

    str = "&&quot;";
    expected = "&\"";
    REQUIRE(HTMLDecode(str) == expected);

    str = "&&&";
    expected = "&&&";
    REQUIRE(HTMLDecode(str) == expected);

    str = "&&&quot;&&&";
    expected = "&&\"&&&";
    REQUIRE(HTMLDecode(str) == expected);
}
