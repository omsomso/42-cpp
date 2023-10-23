#include "Zombie.hpp"

int	main(void)
{
	int		nb_zombies = 5;
	Zombie	*zombie_horde = NULL;

	zombie_horde = zombie_horde->zombieHorde(nb_zombies, "Zob");
	for (int i = 0; i < nb_zombies; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
	return (0);
}
