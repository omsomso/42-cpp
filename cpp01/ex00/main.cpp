#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie = NULL;
	Zombie	zombie_stack;

	zombie = zombie->newZombie("Bob");
	zombie->announce();
	zombie_stack.randomChump("Zean-Michel");

	delete zombie;
	return (0);
}
