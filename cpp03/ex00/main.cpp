#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap robot_1("Robocop");
	ClapTrap robot_2("Terminator");
	ClapTrap robot_3("Optimus Primus Maximus");

	std::cout << "----Begin Fight----" << std::endl;
	robot_2.attack("Robocop");
	robot_1.takeDamage(0);
	robot_1.beRepaired(1);
	robot_3.attack("Robocop");
	robot_1.takeDamage(0);
	std::cout << "----End Fight----" << std::endl;
	
	ClapTrap a("Replicator");
	ClapTrap b(a);
	ClapTrap c = b;

	a.takeDamage(1);
	b.takeDamage(2);
	c.takeDamage(3);
	
	return (0);
}