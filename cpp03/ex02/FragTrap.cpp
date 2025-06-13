#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << ": Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << ": Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << ": high five, guys!!" << std::endl;
}
