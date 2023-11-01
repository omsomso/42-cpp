#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if (grade < 1)
		throw std::runtime_error("Bureaucrat::GradeTooHighException");
	if (grade > 150)
		throw std::runtime_error("Bureaucrat::GradeTooLowException");
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : name(other.name), grade(other.grade) {
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
	this->grade = other.grade;
	return (*this);
}

std::string Bureaucrat::getName() {
	return (this->name);
}

int Bureaucrat::getGrade() {
	return (this->grade);
}

void Bureaucrat::incrementGrade() {
	if (this->grade == 1)
		throw std::runtime_error("Bureaucrat::GradeTooHighException");
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade == 150)
		throw std::runtime_error("Bureaucrat::GradeTooLowException");
	this->grade++;
}
