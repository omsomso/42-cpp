#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string\t\t: " << &string << std::endl;
	std::cout << "Address held by stringPTR\t: " << stringPTR << std::endl;
	std::cout << "Address of stringREF\t\t: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string\t\t\t: " << string << std::endl;
	std::cout << "Value pointed by stringPTR\t: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF\t\t: " << stringREF << std::endl;

	return (0);
}
