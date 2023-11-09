#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	std::cout << ORANGE "Creating robots..." RESET << std::endl;
	ScavTrap robot_1("Robocop");
	ScavTrap robot_2("Terminator");
	ScavTrap robot_3("Optimus Primus Maximus");

	std::cout << ORANGE "Begin Fight" RESET << std::endl;
	robot_2.attack("Robocop");
	robot_1.takeDamage(20);
	robot_2.beRepaired(1);
	robot_3.attack("Robocop");
	robot_1.takeDamage(20);
	robot_3.guardGate();

	std::cout << ORANGE "Copy tests" RESET<< std::endl;
	ScavTrap a("Replicator");
	a.takeDamage(1);
	std::cout << std::endl;

	ScavTrap b(a);
	b.takeDamage(2);
	std::cout << std::endl;

	ScavTrap c = b;
	c.takeDamage(3);
	std::cout << std::endl;
	
	std::cout << ORANGE "Destroying robots..." RESET << std::endl;
	return (0);
}