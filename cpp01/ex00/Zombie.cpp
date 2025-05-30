#include "Zombie.hpp"

Zombie::Zombie(std::string pname)
{
	std::cout << "Zombie: Constructor called" << std::endl;

	name = pname;
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
