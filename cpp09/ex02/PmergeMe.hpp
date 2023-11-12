#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <list>
# include <vector>
# include <sys/time.h>

# define K 2
# define VERBOSE 1

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
		// sort
		void vecInsertionSort(int p, int r);
		void vecMerge(int const left, int const mid, int const right);
		void vecMergeInsertionSort(int const begin, int const end);
		void lstInsertionSort(int p, int r);
		void lstMerge(int const left, int const mid, int const right);
		void lstMergeInsertionSort(int const begin, int const end);
		bool isValidInput(std::string input);
		static int sort(char** av);

		// parser
		int checkInput(char** av);
		int parseVecInput(char** av);
		int parseLstInput(char** av);
		
		// utils
		void writeTime();
		void printVec();
		void printLst();
		bool checkVecSort();
		bool checkLstSort();
};

#endif