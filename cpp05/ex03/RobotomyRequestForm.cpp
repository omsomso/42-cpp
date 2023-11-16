#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45) {
	this->setTarget("Default target");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45) {
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other){
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &other) {
	this->setTarget(other.getTarget());
	this->setSignedStatus(other.getSignedStatus());
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!this->getSignedStatus())
		throw UnsignedFormException();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::cout << "*some drilling noises*" << std::endl;
	srand(clock());
	int random = rand() % 2;
	if (random == 0)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed." << std::endl;
}