#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	newFella = new Zombie(name);
	return (newFella);
}
