#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5), target("Default target") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5), target(target) {
}

std::string PresidentialPardonForm::getTarget() const {
	return (this->target);
}

void PresidentialPardonForm::execute(std::string target) {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
