#include "HumanA.hpp"

HumanA::HumanA()
{
	std::cout << "HumanA: Constructor called" << std::endl;
	return ;
}

HumanA::HumanA(std::string name, Weapon weapon)
{
	std::cout << "HumanA: Constructor called" << std::endl;

	_myName = name;
	_myWeapon = weapon;
	return ;
}

HumanA::~HumanA()
{
	std::cout << "HumanA: Destructor called" << std::endl;
	return ;
}

void	HumanA::attack() const;	//WHAT'S WRONG HERE??
{
	std::cout << _myName << " attacks with their " << _myWeapon << std::endl;
}
