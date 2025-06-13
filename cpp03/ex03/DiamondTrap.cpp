#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = FragTrap(hitPoints);
	
}
