#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc != 3)
	{
		std::cout << "Wrong parameters given\n";
		return 1;
	}

	std::ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);

	if (!file1.is_open() || !file2.is_open()) {
		std::cout << argv[1] << std::endl;
		std::cout << "Failed to read files data";
		return 1;
	}

	std::string str1, str2;
	unsigned int lineCounter = 0;
	bool equal = true;

	while (getline(file1, str1) && getline(file2, str2))
	{
		++lineCounter;
		if (str1 != str2) {
			equal = false;
			break;
		}
	}

	if (file1.bad() || file2.bad()) 
	{
		std::cout << "Failed to read files \n";
		return 1;
	}

	if (equal)
	{
		std::cout << "Files are equal\n";
	}
	else
	{
		std::cout << "Files are different. Line number is " << lineCounter << std::endl;
	}

	return 0;
}