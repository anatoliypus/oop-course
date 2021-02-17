#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argc != 3) {
		std::cout << "Wrong input parameters \n";
		return 1;
	}
	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open()) {
		std::cout << "Failed to open input file \n";
		return 1;
	}

	std::ofstream output;
	output.open(argv[2]);
	if (!output.is_open()) {
		std::cout << "Failed to open output file \n";
		return 1;
	}

	char ch;
	while (input.get(ch)) {
		if (!output.put(ch)) {
			break;
		}
	}

	if (input.bad()) {
		std::cout << "Failed to read data from input file \n";
		return 1;
	}

	if (!output.flush()) {
		std::cout << "Failed to write data to output file \n";
		return 1;
	}
	return 0;
}