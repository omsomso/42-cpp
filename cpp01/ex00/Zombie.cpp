#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " dieded further" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
