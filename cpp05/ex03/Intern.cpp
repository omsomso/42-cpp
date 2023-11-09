#include "Intern.hpp"

Intern::Intern() {
	// std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern &other) {
	// std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern& Intern::operator=(Intern &other) {
	// std::cout << "Intern copy assignemnt operator called" << std::endl;
	(void) other;
	return (*this);
}

Intern::~Intern() {
	// std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
	AForm *form = new ShrubberyCreationForm(target);
	return (form);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
	AForm *form = new RobotomyRequestForm(target);
	return (form);
}
AForm* Intern::createPresidentialPardonForm(std::string target) {
	AForm *form = new PresidentialPardonForm(target);
	return (form);
}

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string formNames[3] = {
		"Shrubbery Creation Form",
		"Robotomy Request Form",
		"Presidential Pardon Form",
	};
	AForm* (Intern::*f[3])(std::string target) = {
			&Intern::createShrubberyCreationForm,
			&Intern::createRobotomyRequestForm,
			&Intern::createPresidentialPardonForm,
	};
	std::cout << "Intern creates " << name << std::endl;
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			return ((this->*f[i])(target));
		}
	}
	std::cout << "Intern couldn't create " << name << " because the form name is invalid" << std::endl;
	return (NULL);
}