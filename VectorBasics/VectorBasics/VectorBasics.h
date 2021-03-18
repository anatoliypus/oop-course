#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

typedef std::vector<double> DoubleVector;
struct Error {
    std::string message;
};

void PrintSortedVector(const DoubleVector& arr);
bool ReadNumbers(DoubleVector& arr, Error& err);
DoubleVector GetProcessedVector(const DoubleVector& arr);
