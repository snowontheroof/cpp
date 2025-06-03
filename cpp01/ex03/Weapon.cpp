#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	std::cout << "Weapon: Constructor called" << std::endl;

	this->type = type;
	return ;
}
Weapon::~Weapon()
{
	std::cout << "Weapon: Destructor called" << std::endl;
	return ;
}

const std::string& Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
	return ;
}
