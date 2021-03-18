#include "VectorBasics.h"

bool ReadNumbers(DoubleVector& arr, Error& err)
{
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            std::istringstream sStream(line);
            double number;
            while (!sStream.eof()) {
                if (!(sStream >> number)) {
                    err.message = "Error in input numbers. You have to give only numeric values";
                    return false;
                }
                arr.push_back(number);
            }
        }
    }
    if (arr.size() == 0) {
        err.message = "No values given. You have to type at least 1 number";
        return false;
    }
    return true;
}

void PrintSortedVector(const DoubleVector& arr)
{
    DoubleVector sortedArr(arr);
    std::sort(sortedArr.begin(), sortedArr.end(), [](double first, double second) {
        return first <= second;
    });
    std::cout.precision(4);
    std::for_each(sortedArr.begin(), sortedArr.end(), [](double i) {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

DoubleVector GetProcessedVector(const DoubleVector& arr)
{
    DoubleVector res;
    res.resize(arr.size());
    double min = *std::min_element(arr.begin(), arr.end());
    std::transform(arr.begin(), arr.end(), res.begin(), [&min](double el) {
        return el * min;
    });
    return res;
}
