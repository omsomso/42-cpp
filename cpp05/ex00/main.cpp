#include "Bureaucrat.hpp"

int main() {
	try {
	}
	catch (Bureaucrat::Exception &e) {
		std::cerr << e.getMessage() << std::endl;
	}
	Bureaucrat vogon("Matt", 130);

	Bureaucrat vogon2("Latt", 150);
	std::cout << vogon << std::endl;
	std::cout << vogon2 << std::endl;

	try {
	vogon2.decrementGrade();
	}
	catch (Bureaucrat::Exception &e) {
		std::cerr << e.getMessage() << std::endl;
	}
	return (0);
}
