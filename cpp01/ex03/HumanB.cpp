#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name; 
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	// std::cout << "destroyed HumanB" << std::endl;
}

void	HumanB::attack(void)
{
	sleep(1);
	if (this->weapon == NULL)
	{
		std::cout << this->name << " has no weapon..." << std::endl;
		sleep(1);
		std::cout << this->name << " attacks with his fists!" << std::endl;
	}
	else
		std::cout << this->name << " attacks with his " << this->weapon->get_type() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	sleep(1);
	std::cout << this->name << " has a new weapon: " << this->weapon->get_type() << std::endl;
}