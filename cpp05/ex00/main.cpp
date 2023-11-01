#include "Bureaucrat.hpp"

int main() {

	try
	{
		Bureaucrat vogon("Matt", 160);
	}
	catch (std::exception &e)
	{
		std::cerr << "IT APPEARS THAT THERE WAS AN ERROR : " << e.what() << std::endl;
	}
	Bureaucrat vogon2("Matt", 150);
	std::cout << "Vogon " << vogon2.getName() << " has grade : " << vogon2.getGrade() << std::endl;
	try {
	vogon2.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << "IT APPEARS THAT THERE WAS AN EROOR : " << e.what() << std::endl;
	}
	return (0);
}
