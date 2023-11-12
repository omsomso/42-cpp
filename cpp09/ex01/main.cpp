#include <iostream>
#include "RPN.hpp"

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Please provide an RPN expression to evaluate" << std::endl;
		return (0);
	}
	if (ac > 2) {
		std::cerr << "Error : Please provide one string" << std::endl;
		return (0);
	}
	std::string input = av[1];
	if (Rpn::calculator(input))
		return (0);
	return (0);
}

// CHECK EX00 MAXINT
// 42*    43+ 45- 47/
// FIX NPOS IN EX00
// check numeric limits in ex00 and ex01