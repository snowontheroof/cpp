#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout << "HumanA: Constructor called" << std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << "HumanA: Destructor called" << std::endl;
	return ;
}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
