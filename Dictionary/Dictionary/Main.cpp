#include "Dictionary.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Dictionary dict;
    Error err;

    if (!ReadDictionary(dict, INPUT_FILENAME, err)) {
        std::cout << err.message << std::endl;
        return 1;
    }
    Conversation(dict);

    DelayBeforeClose();

    return 0;
}
