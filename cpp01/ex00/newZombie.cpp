#include "Zombie.hpp"

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie;
	new_zombie->name = name;
	return (new_zombie);
}
