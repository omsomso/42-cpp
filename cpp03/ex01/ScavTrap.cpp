#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->_name = "Nameless";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called for " << name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;

}

// ScavTrap::ScavTrap(const ScavTrap &other) {
// 	std::cout << "ScavTrap copy constructor called for " << other._name << std::endl;
// 	*this = other;
// }

// ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
// 	std::cout << "ScavTrap copy assignment operator called" << std::endl;
// 	this->_name = other._name;
// 	this->_hitPoints = other._hitPoints;
// 	this->_energyPoints = other._energyPoints;
// 	this->_attackDamage = other._attackDamage;
// 	return (*this);
// }

void ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_hitPoints--;
	std::cout << "ScavTrap " << this->_name << " has " << this->_hitPoints << " hit points left" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "ScavTrap " << this->_name << " repairs itself and gets " << amount << " hit points back" << std::endl;
	this->_hitPoints += amount;
	std::cout << "ScavTrap " << this->_name << " has " << this->_hitPoints << " hit points" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
