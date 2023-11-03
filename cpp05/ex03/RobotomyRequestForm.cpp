#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45), target("Default target") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45), target(target) {
}

std::string RobotomyRequestForm::getTarget() const {
	return (this->target);
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