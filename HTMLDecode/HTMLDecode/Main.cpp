#include "HTMLDecode.h"

int main()
{
    std::string str = ReadStrFromCin();
    std::cout << HTMLDecode(str) << std::endl;
    return 0;
}
