#include "Zombie.hpp"

int	main()
{
	Zombie	Bob("Bob");
	Bob.announce();

	Zombie*	Tero = newZombie("Tero");
	Tero->announce();
	delete (Tero);

	randomChump("Markku");
	return 0;
}
