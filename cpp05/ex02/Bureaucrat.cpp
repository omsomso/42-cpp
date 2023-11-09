#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Nameless bureaucrat") {
	std::cout << "Creating " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) {
	std::cout << "Creating " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	std::cout << "Creating " << name << " with grade " << grade << "..." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat destroyed" << std::endl;
}

const std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	std::cout << this->_name << " incrementing grade..." << std::endl;
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	std::cout << this->_name << " decrementing grade..." << std::endl;
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error : Grade can't be lower than 150.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error : Grade can't be higher than 1.");
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Bureaucrat " << this->getName() << " couldn't sign " << form.getName() << " because it requires at least grade " << form.getGradeSign() << " to be signed." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed form " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " as it requires grade " << form.getGradeExec() << " to be executed." << std::endl;
	}
	catch (AForm::UnsignedFormException) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " as it isn't signed." << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &instance) {
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".";
	return (os);
}