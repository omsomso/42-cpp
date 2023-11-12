#include "PmergeMe.hpp"

bool PmergeMe::isValidInput(std::string input) {
	if (input.empty())
		return (true);
	if (input.find_first_not_of("1234567890-+ ") != std::string::npos) {
		std::cerr << "Error : invalid value : " << input << std::endl;
		return (false);
	}
	try {
		long tmp = std::stol(input);
		if (tmp >= std::numeric_limits<int>::max())
			return (false);
		if (tmp <= std::numeric_limits<int>::min())
			return (false);
	}
	catch (std::exception &e) {
		std::cerr << "Error : invalid value : " << input << std::endl;
		return (false);
	}
	return (true);
}

int	PmergeMe::checkInput(char** av) {
	for (int i = 0; av[i]; i++) {
		std::string tmp = av[i];
		if (!isValidInput(tmp))
			return (1);
	}
	return (0);
}

int PmergeMe::parseVecInput(char** av) {
	gettimeofday(&_vecStart, NULL);
	for (int i = 0; av[i]; i++) {
		std::string tmp = av[i];
		_vecVals.push_back(std::stoi(tmp));
	}
	if (checkVecSort()) {
		std::cerr << "Error : values are already sorted" << std::endl;
		return (1);
	}
	return (0);
}

int PmergeMe::parseLstInput(char** av) {
	gettimeofday(&_lstStart, NULL);
	for (int i = 0; av[i]; i++) {
		std::string tmp = av[i];
		_lstVals.push_back(std::stoi(tmp));
	}
	if (checkLstSort()) {
		std::cerr << "Error : values are already sorted" << std::endl;
		return (1);
	}
	return (0);
}