#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie = NULL;
	zombie = zombie->newZombie("Zob");
	zombie->announce();
	delete zombie;

	Zombie	zombie_stack;
	zombie_stack.randomChump("Zean-Misel");

	return (0);
}
