#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private :
	const std::string _name;
	bool _signedStatus;
	const int _gradeSign;
	const int _gradeExec;
	std::string _target;

	public :
	AForm();
	AForm(std::string name, const int gradeSign, const int gradeExec);
	AForm(AForm& other);
	virtual ~AForm();
	AForm& operator=(AForm& other);

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getSignedStatus() const;
	void beSigned(Bureaucrat const& signer);
	virtual std::string getTarget() const;
	virtual void setTarget(std::string target);
	void setSignedStatus(bool signedStatus);

	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class SignGradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class UnsignedFormException : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& instance);

#endif