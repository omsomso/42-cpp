#include "Weapon.hpp"

int	main(void)
{
	Weapon	weapon;
	weapon.set_type("philosopher's stone");

	HumanA	jean_michel("Jean-Jacques Rousseau", weapon);
	HumanB	jean_pierre("Jean-Paul Sartre");

	jean_michel.attack();
	jean_pierre.attack();
	jean_pierre.setWeapon(weapon);
	jean_pierre.attack();
	jean_michel.attack();
	return (0);
}