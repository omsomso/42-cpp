#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <algorithm>

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
	virtual void makeSound() const ;
};

class Brain {
	private :
	std::string ideas[100];
	
	public :
	Brain();
	Brain(const Brain &other);
	Brain& operator=(const Brain& other);
};

#endif
