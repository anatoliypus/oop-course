#include <fstream>
#include <iostream>
#include <string>

struct Args {
    std::string file1;
    std::string file2;
};

struct Error {
    std::string message;
};

bool ParseArgs(int argc, char* argv[], Args& args, Error& err)
{
    if (argc != 3) {
        err.message = "Wrong arguments given\n";
        return false;
    }
    args.file1 = argv[1];
    args.file2 = argv[2];
    return true;
}

int CompareFiles(std::ifstream& file1, std::ifstream& file2, Error& err)
{
    std::string str1, str2;
    unsigned int lineCounter = 0;
    bool equal = true;

    while (std::getline(file1, str1) && std::getline(file2, str2)) {
        ++lineCounter;
        if (str1 != str2) {
            equal = false;
            break;
        }
    }

    if (file1.bad() || file2.bad()) {
        err.message = "Failed to read files \n";
        return -1;
    }

    if (equal & (!file1.eof() || !file2.eof())) {
        equal = false;
        ++lineCounter;
    }

    if (equal) {
        return 0;
    } else {
        return lineCounter;
    }
}

int main(int argc, char* argv[])
{
    Error err;
    Args args;
    if (!ParseArgs(argc, argv, args, err)) {
        std::cout << err.message;
        return 1;
    }

    if (args.file1 == args.file2) {
        std::cout << "Files are equal\n";
        return 0;
    }

    std::ifstream file1, file2;
    file1.open(args.file1);
    file2.open(args.file2);

    if (!file1.is_open() || !file2.is_open()) {
        std::cout << "Failed to read files data";
        return 1;
    }

    int result = CompareFiles(file1, file2, err);

    if (result == 0) {
        std::cout << "Files are equal\n";
    } else if (result < 0) {
        std::cout << err.message;
        return 1;
    } else {
        std::cout << "Files are different. Line number is " << result << std::endl;
    }

    return 0;
}
