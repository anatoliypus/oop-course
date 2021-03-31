#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define MAX_VALUE 100000000

typedef std::set<int> MainSet;
typedef unsigned long NumType;

struct Error {
    std::string message;
};

bool IsPrime(NumType num);
MainSet GeneratePrimeNumbersSet(NumType upperBound);
bool ParseArgs(int argc, char* argv[], NumType& upperBorder, Error& err);
void PrintOutSet(MainSet& set);
