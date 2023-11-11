#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Error : please provide an input file to evaluate" << std::endl;
		return (1);
	}
	std::string input = av[1];
	if (Btc::convert(input))
		return (1);
	return (0);
}