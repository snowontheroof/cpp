#include "Zombie.hpp"

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
