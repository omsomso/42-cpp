#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", 147, 137), target("Default target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 147, 137), target(target) {
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->target);
}

void ShrubberyCreationForm::execute(std::string target) {
	std::ofstream outFile;
	outFile.open(target.append("_shrubbery"), std::ios::out);
	outFile << ASCIITREE << std::endl;
}
