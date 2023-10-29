#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	protected :

	public :
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	// ScavTrap(const ScavTrap &other);
	// ScavTrap::operator=(const ScavTrap &other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();
	
};

#endif
