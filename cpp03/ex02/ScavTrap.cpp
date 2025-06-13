#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints =  100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << name << ": Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << ": Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack - they are already dead!" << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name
			<< " cannot attack - not enough energy points!" << std::endl;
		return ;
	}
	energyPoints -= 1;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage
		<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
