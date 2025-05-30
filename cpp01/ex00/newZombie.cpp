#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	newzomb = new Zombie(name);
	return (newzomb);
}
