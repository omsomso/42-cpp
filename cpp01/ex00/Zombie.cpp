#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie;
	new_zombie->name = name;
	return (new_zombie);
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " dieded further" << std::endl;
	delete this;
}