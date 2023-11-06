#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#define GREEN "\033[0;32m"
#define ORANGE "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Span {
	private:
	std::vector<int> _numbers;
	unsigned int _N;

	public:
	Span(unsigned int N);
	void addNumber(unsigned int nb);
	int shortestSpan();
	int longestSpan();

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);
};

#include "Span.tpp"

#endif