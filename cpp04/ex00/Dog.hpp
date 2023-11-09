#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public :
	Dog();
	Dog(std::string type);
	Dog(Dog &other);
	~Dog();
	Dog& operator=(Dog& other);

	void makeSound() const ;
};

#endif
