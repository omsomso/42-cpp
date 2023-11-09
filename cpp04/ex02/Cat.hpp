#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	private :
	Brain* _catBrain;

	public :
	Cat();
	Cat(std::string type);
	Cat(Cat& other);
	~Cat();
	Cat& operator=(Cat& other);

	void makeSound() const ;
	void setBrain();
	void printBrain();
};

#endif
