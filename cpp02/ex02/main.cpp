#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	
	std::cout << std::endl;

	Fixed c(100);
	Fixed d(5);

	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;

	std::cout << std::endl;

	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << std::endl;

	bool result;
	Fixed peti(0);
	Fixed gran(10);
	Fixed gran2(10);
	result = peti < gran;
	std::cout << result << std::endl;
	result = peti > gran;
	std::cout << result << std::endl;
	result = peti >= gran;
	std::cout << result << std::endl;
	result = peti <= gran;
	std::cout << result << std::endl;
	result = gran <= gran2;
	std::cout << result << std::endl;
	return (0);
}
