#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A generic Zombie: Constructor called" << std::endl;

	this->name = "A generic Zombie";
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << name << ": Constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << ": Destructor called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
