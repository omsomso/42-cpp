#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	private :
	Brain* catBrain;

	public :
	Cat();
	Cat(std::string type);
	Cat(Cat& other);
	Cat& operator=(Cat& other);
	~Cat();

	void makeSound() const ;
	void setBrain();
	void printBrain();
};

#endif
