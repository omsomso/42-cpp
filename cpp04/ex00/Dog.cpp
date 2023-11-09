#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
}

Dog::Dog(std::string type) : Animal(type) {
}

void Dog::makeSound() const {
	std::cout << "woof!" << std::endl;
}

Dog::~Dog() {}

Dog::Dog(Dog& other) {
	*this = other;
}

Dog& Dog::operator=(Dog& other) {
	this->type = other.getType();
	return (*this);
}