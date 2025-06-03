#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie: Constructor called" << std::endl;
	return ;
}

Zombie::Zombie(std::string name)
{
	std::cout << "Zombie: Constructor called" << std::endl;

	this->name = name;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie: Destructor called" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
