#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

#define ORANGE "\033[33m"
#define RESET "\033[0m"

class ClapTrap
{
	private :
	std::string _name;
	int _hitPoints;
	int	_energyPoints;
	int	_attackDamage;

	public :
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap &other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
