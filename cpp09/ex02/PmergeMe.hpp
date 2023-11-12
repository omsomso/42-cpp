#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <list>
# include <vector>
# include <sys/time.h>

# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define ORANGE "\033[33m"

class PmergeMe {
	private:
		std::list<int> _lstVals;
		std::vector<int> _vecVals;
		timeval _vecStart, _vecEnd, _lstStart, _lstEnd;


	public:
		void vecMerge(int const left, int const mid, int const right);
		void vecMergeSort(int const begin, int const end);
		void lstMerge(int const left, int const mid, int const right);
		void lstMergeSort(int const begin, int const end);
		void printVec();
		void printLst();
		bool checkVecSort();
		bool checkLstSort();
		int checkInput(char** av);
		int parseVecInput(char** av);
		int parseLstInput(char** av);
		bool isValidInput(std::string input);
		static int sort(char** av);
		void writeTime();
};

#endif