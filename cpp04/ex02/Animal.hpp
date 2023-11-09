#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define ORANGE "\033[33m"
# define RESET "\033[0m"

class Animal {
	protected :
	std::string type;

	public :
	Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	Animal& operator=(const Animal &other);
	virtual ~Animal();

	const std::string getType() const;
	virtual void makeSound() const = 0;
	virtual void setBrain();
	virtual void printBrain();
};

#endif
