#include "PrimesGenerator.h"

bool IsPrime(NumType num)
{
    long long sqrtNum = static_cast<NumType>(std::ceil(std::sqrt(num)));

    if (num < 2) {
        return false;
    } else if (num <= 3) {
        return true;
    }

    for (NumType i = 2; i <= sqrtNum; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

MainSet GeneratePrimeNumbersSet(NumType upperBound)
{
    std::vector<bool> nums(upperBound + 1, true);
    nums[0] = nums[1] = false;
    MainSet set;
    long long sqrtUpperBound = static_cast<NumType>(std::ceil(std::sqrt(upperBound)));
    for (NumType i = 2; i <= sqrtUpperBound; i++) {
        if (IsPrime(i)) {
            for (NumType j = 2 * i; j <= upperBound; j += i) {
                nums[j] = false;
            }
        }
    }
    for (NumType i = 0; i <= upperBound; i++) {
        if (nums[i]) {
            set.insert(i);
        }
    }
    return set;
}

bool ParseArgs(int argc, char* argv[], NumType& upperBorder, Error& err)
{
    if (argc != 2) {
        err.message = "Wrong amount of parameters. Usage: *program_path* <Primes upper border>";
        return false;
    } else {
        std::string str = argv[1];
        long inputNumber;
        try {
            inputNumber = std::stol(str);
            std::cout << inputNumber << std::endl;
            if (inputNumber < 0) {
                err.message = "Number must be positive";
                return false;
            }
            if (inputNumber > MAX_VALUE) {
                err.message = "Too big number. Maximum is " + std::to_string(MAX_VALUE);
                return false;
            }
        } catch (...) {
            err.message = "You have to give only numeric positive values less or equal " + std::to_string(MAX_VALUE);
            return false;
        }
        upperBorder = inputNumber;
    }
    return true;
}

void PrintOutSet(MainSet& set)
{
    std::for_each(set.begin(), set.end(), [](NumType el) {
        std::cout << el << " ";
    });
    std::cout << std::endl;
}
