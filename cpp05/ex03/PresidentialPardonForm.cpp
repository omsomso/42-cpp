#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5) {
	this->setTarget("Default target");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5) {
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other){
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other) {
	this->setTarget(other.getTarget());
	this->setSignedStatus(other.getSignedStatus());
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!this->getSignedStatus())
		throw UnsignedFormException();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
