#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private :
	AForm* createShrubberyCreationForm(std::string target);
	AForm* createRobotomyRequestForm(std::string target);
	AForm* createPresidentialPardonForm(std::string target);

	public :
	Intern();
	Intern(Intern &other);
	~Intern();
	Intern& operator=(Intern &other);
	AForm* makeForm(std::string name, std::string target);
};

#endif