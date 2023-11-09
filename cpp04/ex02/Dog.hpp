#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private :
	Brain* _dogBrain;

	public :
	Dog();
	Dog(std::string type);
	Dog(Dog& other);
	~Dog();
	Dog& operator=(Dog& other);

	void makeSound() const ;
	void setBrain();
	void printBrain();
};

#endif
