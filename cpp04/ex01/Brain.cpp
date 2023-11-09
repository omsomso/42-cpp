#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain initialised" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy contructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Deleted brain!" << std::endl;
}

std::string* Brain::getIdeas() {
	return (this->_ideas);
}

void Brain::printIdeas() {
	if (this->_ideas[0].empty()){
		std::cout << "Brain empty!" << std::endl;
		return ;
	}
	std::cout << "First 10 brain ideas are : ";
	for (int i = 0; i < 10; i++)
		std::cout << this->_ideas[i] << " ";
	std::cout << std::endl;
}

void Brain::setIdeas(std::string idea) {
	std::cout << "Setting brain ideas to \"" << idea << "\"... " << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}
