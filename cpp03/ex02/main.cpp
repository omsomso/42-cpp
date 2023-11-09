#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	std::cout << ORANGE "Creating robots..." RESET << std::endl;
	ClapTrap robot_1("Robocop");
	ScavTrap robot_2("Terminator");
	FragTrap robot_3("Optimus Primus Maximus");

	std::cout << ORANGE "Begin Fight" RESET << std::endl;
	robot_2.attack("Optimus Primus Maximus");
	robot_3.takeDamage(20);
	robot_2.beRepaired(1);
	robot_3.attack("Robocop");
	robot_1.takeDamage(30);
	robot_2.guardGate();
	robot_3.highFivesGuys();

	std::cout << ORANGE "Copy tests" RESET<< std::endl;
	FragTrap a("Replicator_v2.0");
	FragTrap b, c, d;
	b.takeDamage(100);
	std::cout << std::endl;
	b = c = d = a;
	std::cout << std::endl;
	a.takeDamage(1);
	b.takeDamage(2);
	c.takeDamage(3);
	d.takeDamage(4);

	std::cout << ORANGE "Destroying robots..." RESET << std::endl;
	return (0);
}