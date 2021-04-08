#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const long MAX_VALUE = 100000000;

typedef std::set<int>
    IntegerSet;
typedef unsigned long NumType;

struct Error {
    std::string message;
};

bool IsPrime(NumType num);
IntegerSet GeneratePrimeNumbersSet(NumType upperBound);
bool ParseArgs(int argc, char* argv[], NumType& upperBorder, Error& err);
void PrintOutSet(IntegerSet& set);
