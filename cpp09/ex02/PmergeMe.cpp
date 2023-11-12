#include "PmergeMe.hpp"

void PmergeMe::vecInsertionSort(int begin, int end) {
	for (int current = begin; current < end; current++) {
		int tempVal = _vecVals[current + 1];
		int upper = current + 1;
		while (upper > begin && _vecVals[upper - 1] > tempVal) {
			_vecVals[upper] = _vecVals[upper - 1];
			upper--;
		}
		_vecVals[upper] = tempVal;
	}
}

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

void PmergeMe::vecMergeInsertionSort(int const begin, int const end) {
	if (end - begin > K) {
		int mid = begin + (end - begin) / 2;
		vecMergeInsertionSort(begin, mid);
		vecMergeInsertionSort(mid + 1, end);
		vecMerge(begin, mid, end);
	}
	else
		vecInsertionSort(begin, end);
}

void PmergeMe::lstInsertionSort(int begin, int end) {

	std::list<int>::iterator itCurrent = _lstVals.begin();
	std::list<int>::iterator itCurrentUp;
	std::list<int>::iterator itEnd = _lstVals.begin();
	std::list<int>::iterator itBegin = _lstVals.begin();
	std::list<int>::iterator itUpper;
	std::list<int>::iterator itLower;

	for (int i = 0; i < begin; i++) {
		itBegin++;
		itCurrent++;
	}
	for (int i = 0; i < end; i++)
		itEnd++;
	while (itCurrent != itEnd) {
		itCurrentUp = itCurrent;
		itCurrentUp++;
		int tempVal = *itCurrentUp;
		itUpper = itCurrentUp;
		itLower = itUpper;
		itLower--;
		while (itUpper != itBegin && *itLower > tempVal) {
			*itUpper = *itLower;
			itUpper--;
		}
		*itUpper = tempVal;
		itCurrent++;
	}
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

void PmergeMe::lstMergeInsertionSort(int const begin, int const end) {
	if (end - begin > K) {
		int mid = begin + (end - begin) / 2;
		lstMergeInsertionSort(begin, mid);
		lstMergeInsertionSort(mid + 1, end);
		lstMerge(begin, mid, end);
	}
	else
		lstInsertionSort(begin, end);

}

int PmergeMe::sort(char **av) {
	PmergeMe algo;
	if (algo.checkInput(av))
		return (1);

	if (algo.parseVecInput(av))
		return (1);
	if (VERBOSE) {
		std::cout << ORANGE "Before\t: ";
		algo.printVec();

	}
	algo.vecMergeInsertionSort(0, algo._vecVals.size() - 1);
	gettimeofday(&algo._vecEnd, NULL);
	if (VERBOSE) {
		std::cout << GREEN "After\t: ";
		algo.printVec();
		std::cout << RESET;
	}
	if (algo.parseLstInput(av))
		return (1);
	algo.lstMergeInsertionSort(0, algo._lstVals.size() - 1);
	gettimeofday(&algo._lstEnd, NULL);
	algo.writeTime();
	
	if (!VERBOSE) {
		if (algo.checkVecSort() && algo.checkLstSort())
			std::cout << GREEN "Values are sorted :)" RESET << std::endl;
		else
			std::cout << RED "Values aren't sorted :(" RESET << std::endl;
	}
	return (0);
}