#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 147, 137) {
	this->setTarget("Default target");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 147, 137) {
	this->setTarget(target);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other) {
	this->setTarget(other.getTarget());
	this->setSignedStatus(other.getSignedStatus());
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) {
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->getSignedStatus())
		throw UnsignedFormException();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();	std::ofstream outFile;
	outFile.open(this->getTarget().append("_shrubbery"), std::ios::out);
	outFile << ASCIITREE << std::endl;
}
