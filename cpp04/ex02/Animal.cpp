#include "Animal.hpp"

Animal::Animal() : type("Undefined") {
	std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called for " << other.type << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignment operator called for " << other.type << std::endl;
	this->type = other.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called for " << this->type << std::endl;
}

const std::string Animal::getType() const {
	return (this->type);
}

void Animal::makeSound() const {
	std::cout << "*default animal sounds*" << std::endl;
}

void Animal::setBrain() {
}

void Animal::printBrain() {
}

// brain class

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
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Deleted brain!" << std::endl;
}

std::string* Brain::getIdeas() {
	return (this->ideas);
}

void Brain::printIdeas() {
	if (this->ideas[0].empty()){
		std::cout << "Head empty!" << std::endl;
		return ;
	}
	std::cout << "First 10 brain ideas are : ";
	for (int i = 0; i < 10; i++)
		std::cout << this->ideas[i] << " ";
	std::cout << std::endl;
}

void Brain::setIdeas(std::string idea) {
	std::cout << "Setting brain ideas to \"" << idea << "\"... " << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}
