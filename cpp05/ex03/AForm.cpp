#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm::AForm() : _name("Nameless form"), _gradeSign(150), _gradeExec(150) {
	std::cout << "Creating Form Nameless form..." << std::endl;
	this->_signedStatus = false;
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	std::cout << "Creating Form " << name << "..." << std::endl;
	this->_signedStatus = false;
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
}

AForm::AForm(AForm& other) : _name(other._name), _signedStatus(other._signedStatus), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

AForm& AForm::operator=(AForm& other) {
	// this->gradeSign = other.gradeSign;
	// this->gradeExecute = other.gradeExecute;
	this->_signedStatus = other._signedStatus;
	return (*this);
}

AForm::~AForm() {
	// std::cout << "Form destroyed" << std::endl;
}

std::string AForm::getName() const {
	return (this->_name);
}

int AForm::getGradeSign() const {
	return (this->_gradeSign);
}

int AForm::getGradeExec() const {
	return (this->_gradeExec);
}

bool AForm::getSignedStatus() const {
	return (this->_signedStatus);
}

std::string AForm::getTarget() const {
	return (this->_target);
}

void AForm::setSignedStatus(bool signedStatus) {
	this->_signedStatus = signedStatus;
}

void AForm::setTarget(std::string target) {
	this->_target = target;
}

void AForm::beSigned(Bureaucrat const& signer) {
	if (signer.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	// if (this->signedStatus == true)
	// 	std::cout << "The form was already signed!" << std::endl;
	else
		this->_signedStatus = true;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Error : A grade can't be lower than 150.");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Error : A grade can't be higher than 1.");
}

const char* AForm::SignGradeTooLowException::what() const throw() {
	return ("Error : Grade too low to sign form");
}

const char* AForm::UnsignedFormException::what() const throw() {
	return ("Error : The form isn't signed");
}

std::ostream& operator<<(std::ostream &os, const AForm &instance) {
	os << "===========Form info===========" << std::endl;
	os << "Form name\t\t: " << instance.getName() << std::endl;
	os << "Signed status\t\t: " << instance.getSignedStatus() << std::endl;
	os << "Minimum grade to sign\t: " << instance.getGradeSign() << std::endl;
	os << "Minimum grade to exec\t: " << instance.getGradeExec() << std::endl;
	os << "===============================";
	return (os);
}
