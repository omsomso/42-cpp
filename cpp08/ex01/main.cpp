#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <random>
#include "Span.hpp"

void subjectTest() {
	std::cout << ORANGE "Subject test:" RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void overflowTest() {
	std::cout << ORANGE "Overflow test:" RESET << std::endl;
	Span sp = Span(5);
	try {
		for (int i = 0; i < 10; i++)
			sp.addNumber(i + i);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void largeTest() {
	std::cout << ORANGE "Large test:" RESET << std::endl;
	Span sp = Span(10001);
	for (int i = 0; i < 10001; i++)
		sp.addNumber(i);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void randomRangeTest() {
	std::cout << ORANGE "Random Range test:" RESET << std::endl;
	std::set<int> set;
	srand(time(NULL));
	while (set.size() < 500) {
		set.insert(rand() % 501);
	}
	Span sp = Span(500);
	sp.addRange(set.begin(), set.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main() {
	subjectTest();
	overflowTest();
	largeTest();
	randomRangeTest();
	return (0);
}