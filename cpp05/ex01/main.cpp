#include "Bureaucrat.hpp"
#include "Form.hpp"

void testValidForm() {
	std::cout << GREEN "---Testing form creation---" RESET << std::endl;
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
	std::cout << GREEN "---Testing form signing---" RESET << std::endl;
	Form form2A("2A", 100, 50);
	std::cout << form2A << std::endl;
	Bureaucrat CanSign("Mr. Cansign", 70);
	CanSign.signForm(form2A);

	Bureaucrat CanNotSign("Mr. Cannotsign", 120);
	CanNotSign.signForm(form2A);

}

int main() {
	testValidForm();
	testFormSign();
	return (0);
}
