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

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class Exception {
		private :
		std::string message;

		public :
		Exception(const std::string message);
		
		std::string getMessage();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance);

#endif