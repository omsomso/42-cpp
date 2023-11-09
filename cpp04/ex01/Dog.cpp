#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	_dogBrain = new Brain;
	// this->setBrain();
}

Dog::Dog(std::string type) : Animal(type) {
	_dogBrain = new Brain;
}

Dog::Dog(Dog& other) {
	std::cout << "Dog copy constructor called " << std::endl;
	*this = other;
}

Dog& Dog::operator=(Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = other.type;
	delete this->_dogBrain;
	this->_dogBrain = new Brain;
	*this->_dogBrain = *other._dogBrain;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Deleting dogBrain..." << std::endl;
	delete _dogBrain;
}

void Dog::makeSound() const {
	std::cout << "woof!" << std::endl;
}

void Dog::setBrain() {
	_dogBrain->setIdeas("treats");
}

void Dog::printBrain() {
	this->_dogBrain->printIdeas();
}