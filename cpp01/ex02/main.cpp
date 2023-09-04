#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string\t: " << &string << std::endl;
	std::cout << "Address of stringPTR\t: " << stringPTR << std::endl;
	std::cout << "Address of stringREF\t: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string\t\t: " << string << std::endl;
	std::cout << "Value ptd by stringPTR\t: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF\t: " << stringREF << std::endl;

	return (0);
}