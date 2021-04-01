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

std::string HTMLDecode(const std::string& str);
std::string ReadStrFromCin();
