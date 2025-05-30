#include "Zombie.hpp"

int	main()
{
	Zombie*	bunch = zombieHorde(8, "Markku");
	for (int i = 0; i < 8; i++)
		bunch[i].announce();
	delete[] bunch;
	return (0);
}
