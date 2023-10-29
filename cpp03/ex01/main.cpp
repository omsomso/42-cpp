#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap robot_1("Robocop");
	ScavTrap robot_2("Terminator");
	ScavTrap robot_3("Optimus Primus Maximus");

	std::cout << "----Begin Fight----" << std::endl;
	robot_2.attack("Robocop");
	robot_1.takeDamage(20);
	robot_2.beRepaired(1);
	robot_3.attack("Robocop");
	robot_1.takeDamage(20);
	robot_3.guardGate();
	std::cout << "----End Fight----" << std::endl;
	
	ScavTrap a("Replicator");
	a.takeDamage(1);
	std::cout << std::endl;

	ScavTrap b(a);
	b.takeDamage(2);
	std::cout << std::endl;

	ScavTrap c = b;
	c.takeDamage(3);
	std::cout << std::endl;
	
	return (0);
}