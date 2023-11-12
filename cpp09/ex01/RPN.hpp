#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <stack>
# include <sstream>

# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define RED "\033[0;31m"

class Rpn {
	private:
		std::stack<std::string> _valStr;
		std::stack<long double> _calcStack;
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