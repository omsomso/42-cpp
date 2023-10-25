#include "Fixed.hpp"

// const int Fixed::bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << 8;
	std::cout << "shifted int value = " << this->value << std::endl;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->value = value;
}

Fixed::Fixed(Fixed &other) {
	this->value = other.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed &other) {
	this->value = other.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}