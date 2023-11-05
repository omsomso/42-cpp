#include <iostream>
#include "whatever.hpp"

void requiredTest() {
	std::cout << GREEN "Test from subject" RESET<< std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main() {

	int a = 2;
	int b = 3;
	std::cout << GREEN "Testing swap with int : " RESET<< std::endl;
	std::cout << a << " " << b << std::endl;
	swap(a, b);
	std::cout << a << " " << b << std::endl;

	std::string c = "salut";
	std::string d = "world";
	std::cout << GREEN "Testing swap with strings : " RESET<< std::endl;
	std::cout << c << " " << d << std::endl;
	swap(c, d);
	std::cout << c << " " << d << std::endl;

	std::cout << GREEN "Testing max with double : " RESET<< std::endl;
	double e = 2.5;
	double f = 3.5;
	std::cout << e << " " << f << std::endl;
	std::cout << max(e, f) << std::endl;

	std::cout << GREEN "Testing min with float : " RESET<< std::endl;
	float g = 21.25f;
	float h = -42.35f;
	std::cout << g << " " << h << std::endl;
	std::cout << min(g, h) << std::endl;

	requiredTest();
	return (0);
}
