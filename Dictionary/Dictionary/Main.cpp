#include "Dictionary.h"

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Dictionary dict;
    Error err;

    std::string fileName;
    if (!ParseArgs(argc, argv, fileName)) {
        fileName = DEFAULT_FILENAME;
    }

    ProcessInputFile(fileName);

    if (!ReadDictionary(dict, fileName, err)) {
        std::cout << err.message << std::endl;
        return 1;
    }
    Conversation(dict, fileName);

    DelayBeforeClose();

    return 0;
}
