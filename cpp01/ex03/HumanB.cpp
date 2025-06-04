#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << "HumanB: Constructor called" << std::endl;

	this->name = name;
	return ;
}

HumanB::~HumanB()
{
	std::cout << "HumanB: Destructor called" << std::endl;
	return ;
}

void	HumanB::attack() const
{
	std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& type)
{
	this->weapon = &type;
	return ;
}
