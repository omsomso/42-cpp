#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

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
	void signForm(Form &form);

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance);

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
	void beSigned(Bureaucrat &instance);

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& instance);


#endif