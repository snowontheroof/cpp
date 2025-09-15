#include "Zombie.hpp"

int	main(void)
{
	try
	{
		Zombie	Kimmo("Kimmo");
		Kimmo.announce();

		Zombie*	Tero = newZombie("Tero");
		Tero->announce();
		delete (Tero);

		randomChump("Markku");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
