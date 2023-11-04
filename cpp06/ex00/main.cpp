#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	(void) argv;
	if (argc != 2) {
		std::cout << "Provide a string value to convert.\nEx : ./convert 42" << std::endl;
		return (0);
	}
	std::string input(argv[1]);
	ScalarConverter::convert(input);
}