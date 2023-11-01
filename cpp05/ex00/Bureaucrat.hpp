#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private :
	const std::string name;
	int grade;

	public :
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat& other);
	Bureaucrat& operator=(Bureaucrat& other);

	std::string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();
};

#endif