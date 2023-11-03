#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private :
	const std::string name;
	bool signedStatus;
	const int gradeSign;
	const int gradeExec;

	public :
	Form();
	Form(std::string name, const int gradeSign, const int gradeExec);
	Form(Form& other);
	Form& operator=(Form& other);
	~Form();

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getSignedStatus() const;
	void beSigned(Bureaucrat &signer);

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class SignGradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& instance);

#endif