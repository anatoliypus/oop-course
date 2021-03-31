#pragma once

#include <iostream>
#include <unordered_map>

struct Error {
    std::string message;
};

enum class Modes {
    read,
    detectSymbol,
    push
};

bool HTMLDecode(std::string& str, std::string& result, Error& err);
std::string ReadStrFromCin();
