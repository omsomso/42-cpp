#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("undefined") {
	std::cout << "WrongAnimal constructor called for " << type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal constructor called for " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal copy constructor called for " << other.type << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal copy assignment operator called for " << other.type << std::endl;
	this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called for " << this->type << std::endl;
}

const std::string WrongAnimal::getType() const {
	return (this->type);
}

void WrongAnimal::makeSound() const {
	std::cout << "*default animal sounds*" << std::endl;
}

// wrong cat stuff

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
}

void WrongCat::makeSound() const {
	std::cout << "meeeoaaaw" << std::endl;
}
