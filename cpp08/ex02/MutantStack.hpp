#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

#define GREEN "\033[0;32m"
#define ORANGE "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

template <typename TYPE>
class MutantStack : public std::stack<TYPE> {
	public:
	typedef typename std::deque<TYPE>::iterator mindfck;
	mindfck begin() {
		return (std::stack<TYPE>::c.begin());
	}
	mindfck end() {
		return (std::stack<TYPE>::c.end());
	}
};

#endif