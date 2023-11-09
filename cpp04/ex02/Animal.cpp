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

void Animal::setBrain() {}

void Animal::printBrain() {}
