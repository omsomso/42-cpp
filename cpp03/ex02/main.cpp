#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap robot_1("Robocop");
	ScavTrap robot_2("Terminator");
	FragTrap robot_3("Optimus Primus Maximus");

	std::cout << "----Begin Fight----" << std::endl;
	robot_2.attack("Optimus Primus Maximus");
	robot_3.takeDamage(20);
	robot_2.beRepaired(1);
	robot_3.attack("Robocop");
	robot_1.takeDamage(30);
	robot_2.guardGate();
	robot_3.highFivesGuys();
	std::cout << "----End Fight----" << std::endl;
	
	std::cout << std::endl;
	FragTrap a("Replicator_v2.0");
	FragTrap b, c, d;
	b.takeDamage(100);
	std::cout << std::endl;
	b = c = d = a;
	a.takeDamage(1);
	b.takeDamage(2);
	c.takeDamage(3);
	d.takeDamage(4);

	return (0);
}