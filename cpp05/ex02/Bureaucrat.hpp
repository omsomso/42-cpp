#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for time()
#include <fstream> // for files

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
	virtual ~Form();

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getSignedStatus() const;
	virtual std::string getTarget() const = 0; // Pure virtual function
	void beSigned(Bureaucrat const& signer);
	
	void execute(Bureaucrat const& executor) const;

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& instance);

class ShrubberyCreationForm : public Form {
	private :
	const std::string target;

	public :
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	virtual std::string getTarget() const;
	static void execute(std::string target);
};

class RobotomyRequestForm : public Form {
	private :
	const std::string target;

	public :
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	virtual std::string getTarget() const;
	static void execute(std::string target);
};

class PresidentialPardonForm : public  Form {
	private :
	const std::string target;

	public :
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	virtual std::string getTarget() const;
	static void execute(std::string target);
};

#endif