#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected :
	std::string type;

	public :
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal& operator=(const WrongAnimal &other);
	~WrongAnimal();
	const std::string getType() const;
	void makeSound() const ;
};

class WrongCat : public WrongAnimal {
	public :
	WrongCat();
	WrongCat(std::string type);
	void makeSound() const ;
};

#endif
