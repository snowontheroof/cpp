#include "Zombie.hpp"

int	main(void)
{
	try
	{
		Zombie*	bunch = zombieHorde(8, "Jouni");

		for (int i = 0; i < 8; i++)
			bunch[i].announce();
		bunch[0].setName("Markku");
		for (int i = 0; i < 8; i++)
			bunch[i].announce();
		delete[] bunch;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
