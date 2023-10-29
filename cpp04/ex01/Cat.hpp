#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public :
	Cat();
	Cat(std::string type);
	void makeSound() const ;
};

#endif
