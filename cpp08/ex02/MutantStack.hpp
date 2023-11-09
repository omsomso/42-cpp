#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

#define ORANGE "\033[33m"
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