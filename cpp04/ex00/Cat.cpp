#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
}

Cat::Cat(std::string type) : Animal(type) {
}

void Cat::makeSound() const {
	std::cout << "meeeoaaaw" << std::endl;
}

Cat::~Cat() {}

Cat::Cat(Cat& other) {
	*this = other;
}

Cat& Cat::operator=(Cat& other) {
	this->type = other.getType();
	return (*this);
}