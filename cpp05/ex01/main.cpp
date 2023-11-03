#include "Bureaucrat.hpp"

void testInstantiation() {
	std::cout << "---Testing valid bureaucrat instantiation---" << std::endl;
	try {
		Bureaucrat Good("Mr. Good", 130);
		std::cout << Good << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---Testing invalid bureaucrat instantiation---" << std::endl;
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
	std::cout << "---Testing valid bureaucrat grade modifications---" << std::endl;

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
	std::cout << "---Testing invalid bureaucrat grade modifications---" << std::endl;

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

void testValidForm() {
	std::cout << "---Testing form creation---" << std::endl;
	try {
		Form tooLow("2Low", -10, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form tooHigh("2High", 1, 160);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form good("Good", 1, 1);
		std::cout << good << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void testFormSign() {
	std::cout << "---Testing form signing---" << std::endl;
	Form form2A("2A", 100, 50);
	std::cout << form2A << std::endl;
	Bureaucrat CanSign("Cansign", 70);
	CanSign.signForm(form2A);

	Bureaucrat CanNotSign("Cannotsign", 120);
	CanNotSign.signForm(form2A);

}

int main() {
	// testInstantiation();
	// testValidGradeMod();
	// testInvalidGradeMod();
	testValidForm();
	testFormSign();
	return (0);
}
