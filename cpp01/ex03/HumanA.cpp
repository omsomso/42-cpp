#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
}

HumanA::~HumanA() {
	// std::cout << "destroyed HumanA" << std::endl;
}

void	HumanA::attack(void) {
	sleep(1);
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}