#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int	main(void)
{
	Weapon	weapon;
	weapon.setType("philosopher's stone");

	HumanA	philoA("Jean-Jacques Rousseau", weapon);
	HumanB	philoB("Jean-Paul Sartre");

	philoA.attack();
	philoB.attack();
	philoB.setWeapon(weapon);
	philoB.attack();
	philoA.attack();
	return (0);
}