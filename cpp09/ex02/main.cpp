#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac < 3) {
		std::cerr << "Error : please provide at least 2 numbers to sort" << std::endl;
		return (0);
	}
	PmergeMe::sort(++av);
	return (0);
}

// https://iq.opengenus.org/merge-insertion-sort/