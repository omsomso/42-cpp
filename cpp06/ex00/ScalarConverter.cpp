#include "ScalarConverter.hpp"

// Define and initialize static members
double ScalarConverter::specialValues[6] = {
    std::numeric_limits<float>::infinity(),
    -std::numeric_limits<float>::infinity(),
    std::numeric_limits<float>::quiet_NaN(),
    std::numeric_limits<double>::infinity(),
    -std::numeric_limits<double>::infinity(),
    std::numeric_limits<double>::quiet_NaN()
};

std::string ScalarConverter::specialInputs[6] = {
    "+inff",
    "-inff",
    "nanf",
    "+inf",
    "-inf",
    "nan"
};

int ScalarConverter::intMin = std::numeric_limits<int>::lowest();
int ScalarConverter::intMax = std::numeric_limits<int>::max();
float ScalarConverter::floatMin = std::numeric_limits<float>::lowest();
float ScalarConverter::floatMax = std::numeric_limits<float>::max();
double ScalarConverter::doubleMin = std::numeric_limits<double>::lowest();
double ScalarConverter::doubleMax = std::numeric_limits<double>::max();

long double ScalarConverter::inputLD = 0.0;

ScalarConverter::ScalarConverter(std::string input) : _input(input) {
	convert(input);
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	this->_input = other._input;
	*this = other;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other) {
	this->_input = other._input;
	return (*this);
}

void ScalarConverter::printSpecialValues(double specialInput) {
	std::cout << "char: " << "Undefined" << std::endl;
	std::cout << "int: " << "Undefined" << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: " << specialInput << "f" << std::endl;
	std::cout << "double: " << specialInput << std::endl;
}

void ScalarConverter::printChar() {
	if (inputLD <= 31 || inputLD >= 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else {
		char inputChar = static_cast<char>(inputLD);
		std::cout << "char: '" << inputChar << "'" << std::endl;
	}
}

void ScalarConverter::printInt() {
	if (inputLD < intMin || inputLD > intMax)
		std::cout << "int: " << "Non displayable" << std::endl;
	else {
		int inputInt = static_cast<int>(inputLD);
		std::cout << "int: " << inputInt << std::endl;
	}
}

void ScalarConverter::printFloat() {
	if (inputLD < floatMin || inputLD > floatMax)
		std::cout << "float: " << "Non displayable" << std::endl;
	else {
		std::cout << "float: " << inputLD << "f" << std::endl;
	}
}

void ScalarConverter::printDouble() {
	if (inputLD < doubleMin || inputLD > doubleMax)
		std::cout << "double: " << "Non displayable" << std::endl;
	else {
		double inputDouble = static_cast<double>(inputLD);
		std::cout << "double: " << inputDouble << std::endl;
	}
}

void ScalarConverter::convert(std::string input) {
	// setInput(input);
	ScalarConverter::inputLD = 0;
	for (int i = 0; i < 6; i++) {
		if (specialInputs[i] == input) {
			printSpecialValues(specialValues[i]);
			return ;
		}
	}
	try {
		inputLD = std::stold(input);
	}
	catch (std::exception &e) {
		inputLD = input[0];
	}
	if (inputLD == std::numeric_limits<long double>::infinity()) {
		printSpecialValues(specialValues[0]);
		return ;
	}
	else if (inputLD == -std::numeric_limits<long double>::infinity()) {
		printSpecialValues(specialValues[1]);
		return ;
	}
	else if (isnan(inputLD)) {
		printSpecialValues(specialValues[5]);
		return ;
	}

	ScalarConverter::printChar();
	ScalarConverter::printInt();
	std::cout << std::fixed << std::setprecision(1);
	ScalarConverter::printFloat();
	ScalarConverter::printDouble();
}
