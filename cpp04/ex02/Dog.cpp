#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	dogBrain = new Brain;
	// this->setBrain();
}

Dog::Dog(std::string type) : Animal(type) {
	dogBrain = new Brain;
}

Dog::Dog(Dog& other) {
	std::cout << "Dog copy constructor called " << std::endl;
	*this = other;
}

Dog& Dog::operator=(Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = other.type;
	delete this->dogBrain;
	this->dogBrain = new Brain;
	*this->dogBrain = *other.dogBrain;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Deleting dogBrain..." << std::endl;
	delete dogBrain;
}

void Dog::makeSound() const {
	std::cout << "woof!" << std::endl;
}

void Dog::setBrain() {
	dogBrain->setIdeas("treats");
}

void Dog::printBrain() {
	this->dogBrain->printIdeas();
}