#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde(int N, std::string name)
{
	Zombie	*zombie_horde;

	zombie_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie_horde[i].name = name;
	return (zombie_horde);
}
