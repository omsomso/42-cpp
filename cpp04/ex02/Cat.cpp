#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	_catBrain = new Brain;
	// this->setBrain();
}

Cat::Cat(std::string type) : Animal(type) {
	_catBrain = new Brain;
}

Cat::Cat(Cat& other) {
	std::cout << "Cat copy constructor called " << std::endl;
	*this = other;
}

Cat& Cat::operator=(Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = other.type;
	delete this->_catBrain;
	this->_catBrain = new Brain;
	*this->_catBrain = *other._catBrain;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Deleting catBrain..." << std::endl;
	delete _catBrain;
}

void Cat::makeSound() const {
	std::cout << "meeeoaaaw" << std::endl;
}

void Cat::setBrain() {
	_catBrain->setIdeas("sleep");
}

void Cat::printBrain() {
	this->_catBrain->printIdeas();
}