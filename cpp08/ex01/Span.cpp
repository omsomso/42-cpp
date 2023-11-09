#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span& other) {
	*this = other;
}

Span::~Span() {}

Span& Span::operator=(Span& other) {
	this->_numbers = other._numbers;
	this->_N = other._N;
	return (*this);
}

void Span::addNumber(unsigned int number) {
	if (_numbers.size() >= _N)
		throw std::runtime_error("Error : the span is full.");
	_numbers.push_back(number);
}

int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in span.");
	std::sort(_numbers.begin(), _numbers.end());
	int shortestSpan = _numbers[1] - _numbers[0];
	for (unsigned int i = 1; i < this->_N; i++) {
		if (_numbers[i] - _numbers[i - 1] < shortestSpan)
			shortestSpan = _numbers[i] - _numbers[i - 1];
	}
	return (shortestSpan);
}

int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in span.");
	std::sort(_numbers.begin(), _numbers.end());
	int longestSpan = _numbers[_numbers.size() - 1] - _numbers[0];
	return (longestSpan);
}