#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	Base *base = new Base();
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();

	std::cout << GREEN "Identifying pointers to types A, B, C and Base : " RESET << std::endl;
	base->identify(a);
	base->identify(b);
	base->identify(c);
	base->identify(base);

	std::cout << GREEN "Identifying references to types A, B, C and Base : " RESET << std::endl;
	base->identify(*a);
	base->identify(*b);
	base->identify(*c);
	base->identify(*base);

	std::cout << GREEN "Random class generation and identification : " RESET << std::endl;
	for (int i = 1; i <= 10; i++) {
		std::cout <<  "Creating class \t: (" << i << ")\t";
		Base *random = base->generate();
		std::cout << "Identifying \t: (" << i << ")\t";
		base->identify(random);
		delete random;
		usleep(50000);
	}

	delete base;
	delete a;
	delete b;
	delete c;
	return (0);
}