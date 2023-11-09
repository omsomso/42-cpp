#include "Bureaucrat.hpp"

void testInstantiation() {
	std::cout << GREEN "--Testing valid bureaucrat instantiation--" RESET << std::endl;
	try {
		Bureaucrat Good("Mr. Good", 130);
		std::cout << Good << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << GREEN "--Testing invalid bureaucrat instantiation--" RESET << std::endl;
	try {
		Bureaucrat TooLow("Mr. Toolow", 160);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat TooHigh("Mr. Toohigh", 0);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testValidGradeMod() {
	std::cout << GREEN "--Testing valid bureaucrat grade modifications--" RESET << std::endl;

	Bureaucrat Crement("Mr. Crement", 100);
	std::cout << Crement << std::endl;
	try {
		Crement.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << Crement << std::endl;
	try {
		Crement.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << Crement << std::endl;
}

void testInvalidGradeMod() {
	std::cout << GREEN "--Testing invalid bureaucrat grade modifications--" RESET << std::endl;

	Bureaucrat NoIncrement("Mr. Noincrement", 1);
	std::cout << NoIncrement << std::endl;
	try {
		NoIncrement.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat NoDecrement("Mr. Nodecrement", 150);
	std::cout << NoDecrement << std::endl;
	try {
		NoDecrement.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	testInstantiation();
	testValidGradeMod();
	testInvalidGradeMod();
	return (0);
}
