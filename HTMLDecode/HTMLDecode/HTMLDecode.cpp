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

bool HTMLDecode(std::string& str, std::string& result, Error& err)
{
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

    for (char& ch : str) {
        if (ch == '&') {
            mode = Modes::detectSymbol;
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
            char symbolToInsert;
            try {
                symbolToInsert = SymbolPairs.at(symbol);
            } catch (std::exception&) {
                err.message = "Unknown special character given: " + symbol;
                return false;
            }
            symbol = "";
            result.push_back(symbolToInsert);
            mode = Modes::read;
        }
    }
    if (mode != Modes::read) {
        err.message = "Wrong HTML syntax given";
        return false;
    }
    return true;
}
