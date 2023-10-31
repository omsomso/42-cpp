#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	new Brain;
}

Dog::Dog(std::string type) : Animal(type) {
	new Brain;
}

void Dog::makeSound() const {
	std::cout << "woof!" << std::endl;
}
