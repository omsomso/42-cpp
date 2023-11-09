#include "ClapTrap.hpp"

int	main(void) {
	std::cout << ORANGE "Creating robots..." RESET << std::endl;
	ClapTrap robot_1("Robocop");
	ClapTrap robot_2("Terminator");
	ClapTrap robot_3("Optimus Primus Maximus");

	std::cout << ORANGE "Begin Fight" RESET << std::endl;
	robot_2.attack("Robocop");
	robot_1.takeDamage(0);
	robot_1.beRepaired(1);
	robot_3.attack("Robocop");
	robot_1.takeDamage(0);

	std::cout << ORANGE "Copy tests" RESET<< std::endl;
	ClapTrap a("Replicator");
	ClapTrap b(a);
	ClapTrap c = b;

	a.takeDamage(1);
	b.takeDamage(2);
	c.takeDamage(3);
	
	std::cout << ORANGE "Destroying robots..." RESET << std::endl;
	return (0);
}