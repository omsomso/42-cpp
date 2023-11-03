#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// enum formType
// {
// 	ShrubberyCreationForm,
// 	RobotomyRequestForm,
// 	PresidentialPardonForm
// };

class Intern {
	private :
	Form* createShrubberyCreationForm(std::string target);
	Form* createRobotomyRequestForm(std::string target);
	Form* createPresidentialPardonForm(std::string target);

	public :
	Intern();
	~Intern();
	Intern(Intern &other);
	Intern& operator=(Intern &other);
	Form* makeForm(std::string name, std::string target);
};

#endif