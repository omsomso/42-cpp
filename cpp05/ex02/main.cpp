#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testFormSign() {
	std::cout << GREEN "---Testing form signing---" RESET << std::endl;

	Bureaucrat root("Mr. Root", 1);
	Bureaucrat noob("Mr. Noob", 150);
	Bureaucrat johnsmith("Mr. Smith", 73);

	ShrubberyCreationForm formA("Test Subject 1");
	RobotomyRequestForm formB("Test Subject 1");
	PresidentialPardonForm formC("Test Subject 1");

	std::cout << formA << std::endl;
	std::cout << formB << std::endl;
	std::cout << formC << std::endl;

	root.signForm(formA);
	root.signForm(formB);
	root.signForm(formC);

	std::cout << formA << std::endl;
	std::cout << formB << std::endl;
	std::cout << formC << std::endl;

	noob.signForm(formA);
	noob.signForm(formB);
	noob.signForm(formC);

	johnsmith.signForm(formA);
	johnsmith.signForm(formB);
	johnsmith.signForm(formC);

	johnsmith.incrementGrade();
	johnsmith.signForm(formB);
}

void testFormExecution() {
	std::cout << GREEN "---Testing form execution---" RESET << std::endl;

	Bureaucrat root("Mr. Root", 1);
	Bureaucrat noob("Mr. Noob", 150);
	Bureaucrat johnsmith("Mr. Smith", 46);

	ShrubberyCreationForm formA("Test Subject 2");
	RobotomyRequestForm formB("Test Subject 2");
	PresidentialPardonForm formC("Test Subject 2");

	root.signForm(formA);
	root.signForm(formB);
	root.signForm(formC);

	std::cout << formA << std::endl;
	std::cout << formB << std::endl;
	std::cout << formC << std::endl;

	root.executeForm(formA);
	root.executeForm(formB);
	root.executeForm(formC);

	noob.executeForm(formA);
	noob.executeForm(formB);
	noob.executeForm(formC);

	johnsmith.executeForm(formA);
	johnsmith.executeForm(formB);
	johnsmith.executeForm(formC);

	johnsmith.incrementGrade();
	johnsmith.executeForm(formB);
}

void testUnsignedFormExecution() {
	std::cout << GREEN "---Testing execution of an unsigned form---" RESET << std::endl;
	
	Bureaucrat root("Mr. Root", 1);
	RobotomyRequestForm formD("Test Subject 3");
	std::cout << formD << std::endl;
	root.executeForm(formD);
	root.signForm(formD);
	root.executeForm(formD);
}

int main() {
	testFormSign();
	testFormExecution();
	testUnsignedFormExecution();
	return (0);
}
