#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <ctime> // for clock()
#include <unistd.h> // for usleep()

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class Base {
	public :
	virtual ~Base();
	Base *generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

#endif