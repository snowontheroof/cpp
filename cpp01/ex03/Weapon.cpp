#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << type << ": Weapon constructor called" << std::endl;
}
Weapon::~Weapon()
{
	std::cout << type << ": Weapon destructor called" << std::endl;
}

const std::string& Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
