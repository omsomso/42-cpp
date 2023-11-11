#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <stack>
# include <sstream>

class Rpn {
	private:
	std::stack<std::string> _valStr;
	std::stack<long> _calcStack;
	bool isValidInput(std::string input);
	bool isNumber(std::string input);
	char findOperator(std::string input);
	int parseInput(std::string input);
	int	calculate();

	public:
	Rpn();
	Rpn(Rpn& other);
	~Rpn();
	Rpn& operator=(Rpn& other);

	static int	calculator(std::string input);

};

#endif