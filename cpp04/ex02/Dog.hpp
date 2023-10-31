#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private :
	Brain* dogBrain;

	public :
	Dog();
	Dog(std::string type);
	Dog(Dog& other);
	Dog& operator=(Dog& other);
	~Dog();

	void makeSound() const ;
	void setBrain();
	void printBrain();
};

#endif
