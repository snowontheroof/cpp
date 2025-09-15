#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout << name << ": HumanA constructor called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name << ": HumanA destructor called" << std::endl;
}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
