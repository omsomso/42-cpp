#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
}

Cat::Cat(std::string type) : Animal(type) {
}

void Cat::makeSound() const {
	std::cout << "meeeoaaaw" << std::endl;
}
