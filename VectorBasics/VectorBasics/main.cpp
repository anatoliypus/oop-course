#pragma once
#include "VectorBasics.h"

int main()
{
    DoubleVector arr;
    Error err;

    if (!ReadNumbers(arr, err)) {
        std::cout << err.message;
        return 1;
    }

    DoubleVector processedArr = GetProcessedVector(arr);

    PrintSortedVector(processedArr);

    return 0;
}
