#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter {
	private :
	std::string _input;
	static long double inputLD;
    static double specialValues[6];
    static std::string specialInputs[6];
	static int intMin;
	static int intMax;
	static float floatMin;
	static float floatMax;
	static double doubleMin;
	static double doubleMax;
	ScalarConverter(std::string input);
	ScalarConverter(ScalarConverter const &other);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &other);

	public :
	static void convert(std::string input);
	static void printSpecialValues(double specialInput);
	static void printChar();
	static void printInt();
	static void printFloat();
	static void printDouble();
	static void printError();
	void setInput(std::string input);
	std::string getInput(std::string input);

};

#endif