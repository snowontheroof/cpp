#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	newfella = new Zombie(name);
	return (newfella);
}
