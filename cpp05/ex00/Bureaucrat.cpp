#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Nameless bureaucrat") {
	std::cout << "Creating " << this->name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : name(name), grade(150) {
	std::cout << "Creating " << this->name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	std::cout << "Creating " << name << " with grade " << grade << "..." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
	this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat destroyed" << std::endl;
}

const std::string Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::incrementGrade() {
	std::cout << this->name << " incrementing grade..." << std::endl;
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	std::cout << this->name << " decrementing grade..." << std::endl;
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error : Bureaucrat grade can't be lower than 150.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error : Bureaucrat grade can't be higher than 1.");

}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &instance) {
	
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".";
	return (os);
}