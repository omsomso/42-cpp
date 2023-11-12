#include "PmergeMe.hpp"

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