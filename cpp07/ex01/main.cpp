#include <iostream>
#include "Iter.hpp"

void toApper(char& c) {
		c = 'A';
}

int main() {
	std::cout << GREEN "Testing string and toApper" RESET << std::endl;

	std::string test = "coucou world!";
	std::cout << test << std::endl;
	iter(&test[0], test.size(), toApper);
	std::cout << test << std::endl;

	std::cout << GREEN "Testing int array and a template toFortyTwoer" RESET << std::endl;

	int intest[4] = {0, 1, -2, 37};
	for (int i = 0; i < 4; i++)
		std::cout << intest[i] << " ";
	std::cout << std::endl;

	iter(intest, (size_t)sizeof(intest) / sizeof(int), toFortyTwoer);

	for (int i = 0; i < 4; i++)
		std::cout << intest[i] << " ";
	std::cout << std::endl;

	std::cout << GREEN "Testing string and an instantiated template of toFortyTwoer" RESET << std::endl;
	std::string test2 = "salut univers";
	std::cout << test2 << std::endl;
	iter(&test2[0], test.size(), toFortyTwoer<char>);
	std::cout << test2 << std::endl;
	return (0);
}
