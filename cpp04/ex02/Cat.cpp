#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	catBrain = new Brain;
	// this->setBrain();
}

Cat::Cat(std::string type) : Animal(type) {
	catBrain = new Brain;
}

Cat::Cat(Cat& other) {
	std::cout << "Cat copy constructor called " << std::endl;
	*this = other;
}

Cat& Cat::operator=(Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = other.type;
	delete this->catBrain;
	this->catBrain = new Brain;
	*this->catBrain = *other.catBrain;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Deleting catBrain..." << std::endl;
	delete catBrain;
}

void Cat::makeSound() const {
	std::cout << "meeeoaaaw" << std::endl;
}

void Cat::setBrain() {
	catBrain->setIdeas("sleep");
}

void Cat::printBrain() {
	this->catBrain->printIdeas();
}