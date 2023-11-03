#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <cstdlib> // for rand()

#include "Form.hpp"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class Form;

class Bureaucrat {
	private :
	const std::string name;
	int grade;

	public :
	Bureaucrat();
	Bureaucrat(const std::string name);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(Bureaucrat& other);
	~Bureaucrat();

	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form) const;
	void executeForm(Form const& form) const;

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance);

#endif