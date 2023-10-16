#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " dieded further" << std::endl;
}

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie;
	new_zombie->name = name;
	return (new_zombie);
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
