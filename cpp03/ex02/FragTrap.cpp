#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_name = "Nameless";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called for " << name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;

}

FragTrap::FragTrap(const FragTrap &other) {
	std::cout << "FragTrap copy constructor called for " << other._name << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_hitPoints--;
	std::cout << "FragTrap " << this->_name << " has " << this->_hitPoints << " hit points left" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FragTrap " << this->_name << " repairs itself and gets " << amount << " hit points back" << std::endl;
	this->_hitPoints += amount;
	std::cout << "FragTrap " << this->_name << " has " << this->_hitPoints << " hit points" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " says : 🖐️" << std::endl;
}
