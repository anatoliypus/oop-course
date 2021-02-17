#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong parameters \n";
		std::cout << "Usage: Bin2Dec.exe <binary number>\n";
		return 1;
	}

	const long unsigned int num = std::stoi(argv[1]);
	std::cout << num << std::endl;
}