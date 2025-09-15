#include "ClapTrap.hpp"

int	main(void)
{
	{
		std::cout << "ClapTrap: Hit points 10, energy points 10, attack damage 0"
			<< std::endl << std::endl;
		std::cout << "----Test 1: Basic test----" << std::endl;
		ClapTrap	guy1("Jari");
		ClapTrap	guy2("Kari");
		std::cout << std::endl
			<< "*Creating a copy of guy2 (Kari) using copy constructor*" << std::endl;
		ClapTrap	guy3(guy2);
		std::cout << std::endl
			<< "*Creating guy4 with default constructor for later use*" << std::endl;
		ClapTrap	guy4;
		std::cout << std::endl;

		guy1.attack("Lari");
		guy2.takeDamage(8);
		guy1.attack("Kari");
		guy2.takeDamage(3);
		guy2.attack("Jari");
		guy2.beRepaired(2);

		std::cout << std::endl
			<< "*Assigning guy4 the values of guy2 (Kari) using copy assignment operator*"
			<< std::endl;
		guy4 = guy2;
		std::cout << std::endl;

		guy4.attack("Jari");
		guy3.attack("Jari");
		guy1.takeDamage(3);
		guy1.beRepaired(1);
		guy1.attack("Kari");
		guy3.takeDamage(14);
		std::cout << std::endl;
	}

	{
		std::cout << std::endl
			<< "----Test 2: Running out of energy points----" << std::endl;
		ClapTrap	guy5("Pasi");
		ClapTrap	guy6("Masi");
		std::cout << std::endl;

		guy6.attack("Pasi");
		guy5.takeDamage(3);
		for (int i = 0; i < 8; i++)
		{
			guy5.attack("Masi");
			guy6.takeDamage(1);
		}
		guy5.beRepaired(2);
		guy5.attack("Masi");
		guy6.takeDamage(3);
		guy5.attack("Masi");
		guy5.beRepaired(1);
		guy6.beRepaired(1);
		std::cout << std::endl;
	}

	return 0;
}
