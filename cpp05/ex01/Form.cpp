#include "Form.hpp"

Form::Form() : name("Nameless form"), gradeSign(150), gradeExec(150) {
	std::cout << "Creating Form Nameless form..." << std::endl;
	this->signedStatus = false;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec) {
	std::cout << "Creating Form " << name << "..." << std::endl;
	this->signedStatus = false;
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
}

Form::Form(Form& other) : name(other.name), signedStatus(other.signedStatus), gradeSign(other.gradeSign), gradeExec(other.gradeExec) {
}

Form& Form::operator=(Form& other) {
	this->signedStatus = other.signedStatus;
	return (*this);
}

Form::~Form() {
}

std::string Form::getName() const {
	return (this->name);
}

int Form::getGradeSign() const {
	return (this->gradeSign);
}

int Form::getGradeExec() const {
	return (this->gradeExec);
}

const char* Form::SignGradeTooLowException::what() const throw() {
	return ("Error : Grade too low to sign form");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Error : A grade can't be lower than 150.");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Error : A grade can't be higher than 1.");
}

bool Form::getSignedStatus() const {
	return (this->signedStatus);
}

void Form::beSigned(Bureaucrat &signer) {
	if (signer.getGrade() > this->getGradeSign())
		throw SignGradeTooLowException();
	if (this->signedStatus == true)
		std::cout << "The form was already signed!" << std::endl;
	else
		this->signedStatus = true;
}

std::ostream& operator<<(std::ostream &os, const Form &instance) {
	os << "===========Form info===========" << std::endl;
	os << "Form name\t\t: " << instance.getName() << std::endl;
	os << "Signed status\t\t: " << instance.getSignedStatus() << std::endl;
	os << "Minimum grade to sign\t: " << instance.getGradeSign() << std::endl;
	os << "Minimum grade to exec\t: " << instance.getGradeExec() << std::endl;
	os << "===============================";
	return (os);
}
