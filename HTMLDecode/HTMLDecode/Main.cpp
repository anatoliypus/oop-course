#include "HTMLDecode.h"

int main()
{
    std::string str = ReadStrFromCin();
    std::string result;
    Error err;
    if (!HTMLDecode(str, result, err)) {
        std::cout << err.message;
        return 1;
    }
    std::cout << result << std::endl;
    return 0;
}
