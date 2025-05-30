#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	horde = new Zombie[N];	//STUDY ALL THIS STUFF AND ALSO DELETE[]

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
