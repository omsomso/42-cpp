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
	return ("Error : Grade can't be 151 or lower.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error : Grade can't be 0 or higher.");
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Bureaucrat " << this->getName() << " couldn't sign " << form.getName() << " because it requires at least grade " << form.getGradeSign() << " to be signed." << std::endl;
	}
}

void Bureaucrat::executeForm(Form const& form) const {
	try {
		form.execute(*this);
	}
	catch (std::exception) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " as it requires grade " << form.getGradeExec() << " to be executed." << std::endl;
	}
	std::cout << this->getName() << " executed form " << form.getName() << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &instance) {
	
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".";
	return (os);
}


// Definitions for form class


Form::Form() : name("Nameless form"), gradeSign(150), gradeExec(150) {
	std::cout << "Creating Form Nameless form..." << std::endl;
	this->signedStatus = false;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec) {
	std::cout << "Creating Form " << name << "..." << std::endl;
	this->signedStatus = false;
	if (gradeSign > 150 || gradeExec > 150)
		throw Bureaucrat::GradeTooLowException();
	if (gradeSign < 1 || gradeExec < 1)
		throw Bureaucrat::GradeTooHighException();
}

Form::Form(Form& other) : name(other.name), signedStatus(other.signedStatus), gradeSign(other.gradeSign), gradeExec(other.gradeExec) {
}

Form& Form::operator=(Form& other) {
	// this->gradeSign = other.gradeSign;
	// this->gradeExecute = other.gradeExecute;
	this->signedStatus = other.signedStatus;
	return (*this);
}

Form::~Form() {
	// std::cout << "Form destroyed" << std::endl;
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

bool Form::getSignedStatus() const {
	return (this->signedStatus);
}

void Form::execute(Bureaucrat const& executor) const {
	// executor.executeForm(*this);
	if (executor.getGrade() >= this->getGradeExec())
		throw GradeTooLowException();
	if (this->getName() == "Shrubbery Creation Form")
		ShrubberyCreationForm::execute(this->getTarget());
	else if (this->getName() == "Robotomy Request Form")
		RobotomyRequestForm::execute(this->getTarget());
	else if (this->getName() == "Presidential Pardon Form")
		PresidentialPardonForm::execute(this->getTarget());
}

void Form::beSigned(Bureaucrat const& signer) {
	if (signer.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	if (this->signedStatus == true)
		std::cout << "The form was already signed!" << std::endl;
	else
		this->signedStatus = true;
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Error : Grade too low to sign form");
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


// Specific form definitions


ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", 147, 137), target("Default target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 147, 137), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45), target("Default target") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45), target(target) {
}

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5), target("Default target") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5), target(target) {
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->target);
}

std::string RobotomyRequestForm::getTarget() const {
	return (this->target);
}

std::string PresidentialPardonForm::getTarget() const {
	return (this->target);
}

void ShrubberyCreationForm::execute(std::string target) {
	std::ofstream outFile;
	outFile.open(target.append("_shrubbery"), std::ios::out);
	outFile << "new_folder/\n├─ new_file\n├─ new_folder/\nnew_folder/\nnew_file" << std::endl;
}

void RobotomyRequestForm::execute(std::string target) {
	std::cout << "*some drilling noises*" << std::endl;
	srand(static_cast<unsigned>(time(0)));
	int random = rand() % 2;
	if (random == 0) {
		std::cout << target << " has been robotomized successfully." << std::endl;
	}
	else {
		std::cout << target << " robotomization failed." << std::endl;
	}
}

void PresidentialPardonForm::execute(std::string target) {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
