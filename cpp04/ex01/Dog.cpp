#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
}

Dog::Dog(std::string type) : Animal(type) {
}

void Dog::makeSound() const {
	std::cout << "woof!" << std::endl;
}
