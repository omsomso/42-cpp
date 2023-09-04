#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <unistd.h>

# define SEC 100000

class	Weapon
{
	private :
		std::string	type;
	
	public :
		const std::string	&get_type(void);
		void				set_type(std::string type);
};

class	HumanA
{
	private :
		std::string name;
		Weapon		&weapon;
	
	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack(void);
};

class	HumanB
{
	private :
		std::string name;
		Weapon		*weapon;

	public :
		HumanB(std::string name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif