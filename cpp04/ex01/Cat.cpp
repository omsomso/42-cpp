#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	new Brain;
}

Cat::Cat(std::string type) : Animal(type) {
	new Brain;
}

void Cat::makeSound() const {
	std::cout << "*judges you silently*" << std::endl;
}
