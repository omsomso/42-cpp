#include "Fixed.hpp"
#include <cmath>

// const int Fixed::bits = 8;

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;
	this->value = value << Fixed::bits;
	// std::cout << "shifted int value = " << this->value << std::endl;
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;
	this->value = (roundf((value * (1 << this->bits))));
	// std::cout << "shifted float value = " << this->value << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}

Fixed& Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (*this != other)
		this->value = other.value;
	return (*this);
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed &other) {
	if (this->value > other.value)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) {
	if (this->value >= other.value)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other) {
	if (this->value < other.value)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) {
	if (this->value <= other.value)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) {
	if (this->value != other.value)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &other) {
	return (Fixed((this->toFloat() + other.toFloat())));
}

Fixed Fixed::operator-(const Fixed &other) {
	return (Fixed((this->toFloat() - other.toFloat())));
}

Fixed Fixed::operator*(const Fixed &other) {
	return (Fixed((this->toFloat() * other.toFloat())));
}

Fixed Fixed::operator/(const Fixed &other) {
	return (Fixed((this->toFloat() / other.toFloat())));
}

Fixed Fixed::operator++(int) {
	Fixed out(*this);
	this->value++;
	return (out);
}
Fixed& Fixed::operator++() {
	this->value++;
	return (*this);
}

Fixed& Fixed::min(Fixed &one, Fixed &two) {
	if (one.value < two.value)
		return (one);
	return (two);
}

Fixed& Fixed::max(Fixed &one, Fixed &two) {
	if (one.value > two.value)
		return (one);
	return (two);
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &two) {
	if (one.value < two.value)
		return (one);
	return (two);
}

const Fixed& Fixed::max(const Fixed &one, const Fixed &two) {
	if (one.value > two.value)
		return (one);
	return (two);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int	Fixed::toInt(void) const {
	return (this->value >> this->bits);
}

float Fixed::toFloat(void) const {
	return ((this->value / float(1 << this->bits)));
}

std::ostream& operator << (std::ostream &str, const Fixed &number) {
	return (str << number.toFloat());
}
