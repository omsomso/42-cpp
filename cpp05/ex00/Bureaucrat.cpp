#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Nameless") {
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if (grade < 1)
		throw Exception("Bureaucrat::GradeTooHighException");
	if (grade > 150)
		throw Exception("Bureaucrat::GradeTooLowException");
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : name(other.name), grade(other.grade) {
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
	this->grade = other.grade;
	return (*this);
}

const std::string Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() {
	return (this->grade);
}

void Bureaucrat::incrementGrade() {
	if (this->grade == 1)
		throw Exception("Bureaucrat::GradeTooHighException");
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade == 150)
		throw Exception("Bureaucrat::GradeTooLowException");
	this->grade++;
}

Bureaucrat::Exception::Exception(std::string message) : message(message) {
}

std::string Bureaucrat::Exception::getMessage() {
	return (this->message);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &instance) {
	
	os << instance.getName() << " bureaucrat grade " << instance.getGrade();
	return (os);
}