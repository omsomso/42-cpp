#include "PmergeMe.hpp"

void PmergeMe::vecMerge(int const left, int const mid, int const right) {
	int const leftBound = mid - left + 1;
	int const rightBound = right - mid;

	std::vector<int> tmpLeft, tmpRight;

	for (int i = 0; i < leftBound; i++)
		tmpLeft.push_back(_vecVals[left + i]);
	for (int j = 0; j < rightBound; j++)
		tmpRight.push_back(_vecVals[mid + 1 + j]);

	int idxLeft = 0, idxRight = 0;
	int idxMerged = left;

	while (idxLeft < leftBound && idxRight < rightBound) {
		if (tmpLeft[idxLeft] < tmpRight[idxRight])
			_vecVals[idxMerged++] = tmpLeft[idxLeft++];
		else
			_vecVals[idxMerged++] = tmpRight[idxRight++];
	}

	while (idxLeft < leftBound)
		_vecVals[idxMerged++] = tmpLeft[idxLeft++];

	while (idxRight < rightBound)
		_vecVals[idxMerged++] = tmpRight[idxRight++];
}

void PmergeMe::vecMergeSort(int const begin, int const end) {
	if (begin >= end)
		return ;
	int mid = begin + (end - begin) / 2;
	vecMergeSort(begin, mid);
	vecMergeSort(mid + 1, end);
	vecMerge(begin, mid, end);
}

void PmergeMe::lstMerge(int const left, int const mid, int const right) {
	int const leftBound = mid - left + 1;
	int const rightBound = right - mid;

	std::list<int> tmpLeft, tmpRight;
	std::list<int>::iterator itMerged = _lstVals.begin();

	for (int i = 0; i < left; i++)
		itMerged++;

	for (int i = 0; i < leftBound; i++) {
		tmpLeft.push_back(*itMerged);
		itMerged++;
	}

	for (int j = 0; j < rightBound; j++) {
		tmpRight.push_back(*itMerged);
		itMerged++;
	}

	std::list<int>::iterator itLeft = tmpLeft.begin();
	std::list<int>::iterator itRight = tmpRight.begin();
	itLeft = tmpLeft.begin();
	itRight = tmpRight.begin();
	itMerged = _lstVals.begin();
	for (int i = 0; i < left; i++)
		itMerged++;

	while (itLeft != tmpLeft.end() && itRight != tmpRight.end()) {
		if (*itLeft < *itRight) {
			*itMerged = *itLeft;
			itLeft++;
		}
		else {
			*itMerged = *itRight;
			itRight++;
		}
		itMerged++;
	}

	while (itLeft != tmpLeft.end()) {
		*itMerged = *itLeft;
		itMerged++;
		itLeft++;
	}

	while (itRight != tmpRight.end()) {
		*itMerged = *itRight;
		itMerged++;
		itRight++;
	}
}

void PmergeMe::lstMergeSort(int const begin, int const end) {
	if (begin >= end)
		return ;

	int mid = begin + (end - begin) / 2;
	lstMergeSort(begin, mid);
	lstMergeSort(mid + 1, end);
	lstMerge(begin, mid, end);
}

void PmergeMe::printVec() {
	for (size_t i = 0; i < _vecVals.size(); i++) {
		std::cout << _vecVals[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printLst() {
	for (std::list<int>::iterator it = _lstVals.begin(); it != _lstVals.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool PmergeMe::checkVecSort() {
	for (size_t i = 0; i < _vecVals.size() - 1; i++) {
		if (_vecVals[i] > _vecVals[i + 1])
			return (false);
	}
	return (true);
}

bool PmergeMe::checkLstSort() {
	std::list<int>::iterator it = _lstVals.begin();
	std::list<int>::iterator next = _lstVals.begin();
	next++;
	for (size_t i = 0; i < _lstVals.size() - 1; i++) {
		if (*it > *next)
			return (false);
		it++;
		next++;
	}
	return (true);
}

void PmergeMe::writeTime() {
	long vecSec = _vecEnd.tv_sec - _vecStart.tv_sec;
	long vecMsec = _vecEnd.tv_usec - _vecStart.tv_usec;
	long vecTime = vecSec * 1000000 + vecMsec;
	long lstSec = _lstEnd.tv_sec - _lstStart.tv_sec;
	long lstMsec = _lstEnd.tv_usec - _lstStart.tv_usec;
	long lstTime = lstSec * 1000000 + lstMsec;

	std::cout << RESET "Time to process a range of " << _vecVals.size() << " elements with std::vector<int>\t: " GREEN << vecTime << "us" RESET << std::endl;
	std::cout << "Time to process a range of " << _lstVals.size() << " elements with std::list<int>\t: " GREEN << lstTime << "us" RESET << std::endl;
}

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

int PmergeMe::sort(char **av) {
	PmergeMe algo;
	if (algo.checkInput(av))
		return (1);

	if (algo.parseVecInput(av))
		return (1);
	std::cout << ORANGE "Before\t: ";
	algo.printVec();
	algo.vecMergeSort(0, algo._vecVals.size() - 1);
	gettimeofday(&algo._vecEnd, NULL);
	std::cout << GREEN "After\t: ";
	algo.printVec();
	std::cout << RESET;

	if (algo.parseLstInput(av))
		return (1);
	// std::cout << ORANGE "Unsorted list\t: ";
	// algo.printLst();
	algo.lstMergeSort(0, algo._lstVals.size() - 1);
	gettimeofday(&algo._lstEnd, NULL);
	// std::cout << GREEN "Sorted list\t: ";
	// algo.printLst();
	algo.writeTime();
	
	// if (algo.checkVecSort() && algo.checkLstSort())
	// 	std::cout << GREEN "Values are sorted :)" RESET << std::endl;
	// else
	// 	std::cout << RED "Values aren't sorted :(" RESET << std::endl;
	return (0);
}