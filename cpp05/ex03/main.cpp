#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testFormSign() {
	std::cout << GREEN "---Testing form signing---" RESET << std::endl;

	Bureaucrat root("Mr. Root", 1);
	Bureaucrat noob("Mr. Noob", 150);
	Bureaucrat johnsmith("Mr. Smith", 73);
	Intern randomIntern;

	AForm *formA = randomIntern.makeForm("Shrubbery Creation Form", "Test Subject 1");
	AForm *formB = randomIntern.makeForm("Robotomy Request Form", "Test Subject 1");
	AForm *formC = randomIntern.makeForm("Presidential Pardon Form", "Test Subject 1");

	std::cout << *formA << std::endl;
	std::cout << *formB << std::endl;
	std::cout << *formC << std::endl;

	root.signForm(*formA);
	root.signForm(*formB);
	root.signForm(*formC);

	std::cout << *formA << std::endl;
	std::cout << *formB << std::endl;
	std::cout << *formC << std::endl;

	noob.signForm(*formA);
	noob.signForm(*formB);
	noob.signForm(*formC);

	johnsmith.signForm(*formA);
	johnsmith.signForm(*formB);
	johnsmith.signForm(*formC);

	johnsmith.incrementGrade();
	johnsmith.signForm(*formB);

	delete formA;
	delete formB;
	delete formC;
}

void testFormExecution() {
	std::cout << GREEN "---Testing form execution---" RESET << std::endl;

	Bureaucrat root("Mr. Root", 1);
	Bureaucrat noob("Mr. Noob", 150);
	Bureaucrat johnsmith("Mr. Smith", 46);
	Intern randomIntern;

	AForm *formA = randomIntern.makeForm("Shrubbery Creation Form", "Test Subject 2");
	AForm *formB = randomIntern.makeForm("Robotomy Request Form", "Test Subject 2");
	AForm *formC = randomIntern.makeForm("Presidential Pardon Form", "Test Subject 2");

	root.signForm(*formA);
	root.signForm(*formB);
	root.signForm(*formC);

	std::cout << *formA << std::endl;
	std::cout << *formB << std::endl;
	std::cout << *formC << std::endl;

	root.executeForm(*formA);
	root.executeForm(*formB);
	root.executeForm(*formC);

	noob.executeForm(*formA);
	noob.executeForm(*formB);
	noob.executeForm(*formC);

	johnsmith.executeForm(*formA);
	johnsmith.executeForm(*formB);
	johnsmith.executeForm(*formC);

	johnsmith.incrementGrade();
	johnsmith.executeForm(*formB);

	std::cout << GREEN "---Testing execution of an unsigned form---" RESET << std::endl;
	AForm *formD = randomIntern.makeForm("Robotomy Request Form", "Test Subject 3");
	std::cout << *formD << std::endl;
	root.executeForm(*formD);
	root.signForm(*formD);
	root.executeForm(*formD);

	delete formA;
	delete formB;
	delete formC;
	delete formD;
}

int main() {
	testFormSign();
	testFormExecution();
	return (0);
}
