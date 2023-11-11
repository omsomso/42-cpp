#include "RPN.hpp"

Rpn::Rpn() {}

Rpn::Rpn(Rpn& other) {
	*this = other;
}

Rpn::~Rpn() {}

Rpn& Rpn::operator=(Rpn& other) {
	this->_valStr = other._valStr;
	this->_calcStack = other._calcStack;
	return (*this);
}

bool Rpn::isValidInput(std::string input) {
	if (input.empty())
		return (0);
	if (!input.find_first_not_of("1234567890") && input.length() == 1) {
		if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')
			return (true);
		else
			return (false);
	}
	long nb = 0;
	try {
		nb = std::stol(input);
	}
	catch (std::exception &e) {
		return (false);
	}
	nb = std::stol(input);
	if (nb < 0 || nb > 10)
		return (false);
	return (true);
}

bool Rpn::isNumber(std::string input) {
	if (input.empty())
		return (0);
	if (!input.find_first_not_of("1234567890") && input.length() == 1) {
		if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')
			return (false);
		else
			return (false);
	}
	long nb = 0;
	try {
		nb = std::stol(input);
		(void) nb;
	}
	catch (std::exception &e) {
		return (false);
	}
	// nb = std::stol(input);
	// if (nb < 0 || nb > 10)
	// 	return (false);
	return (true);
}

char Rpn::findOperator(std::string input) {
	if (input.empty())
		return (0);
	if (!input.find_first_not_of("1234567890") && input.length() == 1) {
		if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')
			return (input[0]);
		else
			return (false);
	}
	return (false);
}

int	Rpn::parseInput(std::string input) {
	if (input.empty()) {
		std::cerr << "Please provide a valid input" << std::endl;
		return (1);
	}
	std::string valStr;
	std::stringstream ss(input);
	std::string tmp;
	std::stack<std::string> tmpStack;
	while (std::getline(ss, tmp, ' ')) {
		if (!isValidInput(tmp)) {
			std::cerr << "Error : invalid input : \"" << tmp << "\"" << std::endl;
			return (1);
		}
		tmpStack.push(tmp);
	}
	while (!tmpStack.empty()) {
		_valStr.push(tmpStack.top());
		tmpStack.pop();
	}
	return (0);
}

int Rpn::calculate() {
	if (_valStr.empty()) {
		std::cerr << "Empty stack!" << std::endl;
	}
	int a = 0;
	int b = 0;
	while (!_valStr.empty()) {
		if (_valStr.empty()) {
			return (_calcStack.top());
		}
		if (isNumber(_valStr.top())) {
			_calcStack.push(std::stol(_valStr.top()));
			_valStr.pop();
		}
		else if (findOperator(_valStr.top()) == '*') {
			a = _calcStack.top();
			_calcStack.pop();
			b = _calcStack.top();
			_calcStack.pop();
			_calcStack.push(a * b);
			_valStr.pop();
		}
		else if (findOperator(_valStr.top()) == '+') {
			a = _calcStack.top();
			_calcStack.pop();
			b = _calcStack.top();
			_calcStack.pop();
			_calcStack.push(a + b);
			_valStr.pop();
		}
		else if (findOperator(_valStr.top()) == '-') {
			a = _calcStack.top();
			_calcStack.pop();
			b = _calcStack.top();
			_calcStack.pop();
			_calcStack.push(b - a);
			_valStr.pop();
		}
		else if (findOperator(_valStr.top()) == '/') {
			a = _calcStack.top();
			if (a == 0) {
				std::cerr << "Illegal" << std::endl;
				return (1);
			}
			_calcStack.pop();
			b = _calcStack.top();
			_calcStack.pop();
			_calcStack.push(b / a);
			_valStr.pop();
		}
	}
	std::cout << _calcStack.top() << std::endl;
	return (0);
}

int	Rpn::calculator(std::string input) {
	Rpn calculator;
	if (calculator.parseInput(input))
		return (1);
	if (calculator.calculate())
		return (1);
	return (0);
}