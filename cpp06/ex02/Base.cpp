#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* Base::generate(void) {
	srand(static_cast<unsigned>(clock()));
	switch (rand() % 3) {
		case 0: {
			std::cout << "Created A!" << std::endl;
			return (new A());
		}
		case 1: {
			std::cout << "Created B!" << std::endl;
			return (new B());
		}
		case 2: {
			std::cout << "Created C!" << std::endl;
			return (new C());
		}
	}
	return (NULL);
}

void Base::identify(Base* p) {
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a != NULL)
		std::cout << "Identified A!" << std::endl;
	else if (b != NULL)
		std::cout << "Identified B!" << std::endl;
	else if (c != NULL)
		std::cout << "Identified C!" << std::endl;
	else
		std::cout << "Unkown type" << std::endl;
}

void Base::identify(Base& p) {
	A a;
	B b;
	C c;
	bool success = false;

	try {
		a = dynamic_cast<A&>(p);
		std::cout << "Identified A!" << std::endl;
		success = true;
	}
	catch (std::bad_cast& bc) {
	}
	try {
		b = dynamic_cast<B&>(p);
		std::cout << "Identified B!" << std::endl;
		success = true;
	}
	catch (std::bad_cast& bc) {
	}
	try {
		c = dynamic_cast<C&>(p);
		std::cout << "Identified C!" << std::endl;
		success = true;
	}
	catch (std::bad_cast& bc) {
	}
	if (!success)
		std::cout << "Unkown type" << std::endl;
}
