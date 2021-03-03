#include <iostream>
#include <string>

struct Error {
    std::string message;
};

bool ParseArgs(int argc, char* const argv[], std::string& input, Error& err)
{
    if (argc != 2) {
        err.message = "Wrong command line parameters";
        return false;
    }
    input = argv[1];
    return true;
}

bool ConvertBinToDec(const std::string& input, std::size_t& res, Error& err)
{
    std::size_t length = input.length();
    std::size_t i;
    res = 0;
    for (i = 0; i < length; i++) {
        char ch = input[i];
        if (ch == '1') {
            res++;
        } else if (ch != '0') {
            err.message = "Wrong input number";
            return false;
        }
        if (i + 1 < length) {
            res = res << 1;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    Error err;
    std::string input;
    if (!ParseArgs(argc, argv, input, err)) {
        std::cout << err.message;
        return 1;
    }
    size_t result;
    if (!ConvertBinToDec(input, result, err)) {
        std::cout << err.message;
        return 1;
    }
    std::cout << result << std::endl;
    return 0;
}
