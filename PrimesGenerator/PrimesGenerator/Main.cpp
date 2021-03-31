#include "PrimesGenerator.h"

int main(int argc, char* argv[])
{
    Error err;
    NumType upperborder;
    if (!ParseArgs(argc, argv, upperborder, err)) {
        std::cout << err.message << std::endl;
        return 1;
    }
    MainSet set;
    set = GeneratePrimeNumbersSet(upperborder);
    PrintOutSet(set);
    return 0;
}
