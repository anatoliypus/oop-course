#include "HTMLDecode.h"

std::string ReadStrFromCin()
{
    std::string result;
    char ch;
    while ((ch = std::getchar()) != EOF) {
        result.push_back(ch);
    }
    return result;
}

std::string HTMLDecode(const std::string& str)
{
    std::string result;
    std::unordered_map<std::string, char> SymbolPairs = {
        { "&quot", '"' },
        { "&apos", '`' },
        { "&lt", '<' },
        { "&gt", '>' },
        { "&amp", '&' },
    };
    auto mode = Modes::read;
    std::string symbol;

    result = "";

    for (const char& ch : str) {
        if (ch == '&') {
            mode = Modes::detectSymbol;
            if (!symbol.empty()) {
                symbol = "";
                result.push_back('&');
            }
        } else if (ch == ';' && mode == Modes::detectSymbol) {
            mode = Modes::push;
        }

        if (mode == Modes::read) {
            result.push_back(ch);
        }
        if (mode == Modes::detectSymbol) {
            symbol.push_back(ch);
        }
        if (mode == Modes::push) {
            auto symbolToInsertIterator = SymbolPairs.find(symbol);
            if (symbolToInsertIterator == SymbolPairs.end()) {
                result += symbol + ';';
            } else {
                result.push_back(std::get<1>(*symbolToInsertIterator));
            }
            mode = Modes::read;
            symbol = "";
        }
    }
    if (mode != Modes::read) {
        result += symbol;
    }
    return result;
}
