#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "ScavTrap: Hit points 100, energy points 50, attack damage 20"
			<< std::endl << std::endl;
		std::cout << "----Test 1: Basic test----" << std::endl;
		ScavTrap	Joe("Joe");
		ScavTrap	Martin("Martin");

		Joe.attack("Martin");
		Martin.takeDamage(20);
		Martin.attack("Joe");
		Joe.takeDamage(4);
		Joe.attack("Martin");
		Martin.takeDamage(20);
		Martin.attack("Joe");
		Joe.takeDamage(50);
		Joe.attack("Martin");
		Martin.takeDamage(58);
		Martin.beRepaired(2);
		Martin.guardGate();
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << "----Test 2----" << std::endl;
		ScavTrap	Joseph("Joseph");
		ScavTrap	Steve("Steve");

		Steve.guardGate();
		Steve.attack("Joseph");
		Joseph.takeDamage(94);
		Steve.attack("Joseph");
		Joseph.takeDamage(4);
		Joseph.beRepaired(3);
		Steve.attack("Joseph");
		Joseph.takeDamage(6);
		Joseph.beRepaired(2);
		Steve.attack("Joseph");
		Joseph.takeDamage(20);
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << "----Test 3----" << std::endl;
		ScavTrap	guy1("Jari");
		ScavTrap	guy2("Kari");
		std::cout << std::endl
			<< "*Creating a copy of guy2 (Kari) using copy constructor*" << std::endl;
		ScavTrap	guy3(guy2);
		std::cout << std::endl
			<< "*Creating guy4 with default constructor for later use*" << std::endl;
		ScavTrap	guy4;
		std::cout << std::endl;

		guy1.attack("Lari");
		guy2.takeDamage(80);
		guy1.attack("Kari");
		guy2.takeDamage(23);
		guy2.attack("Jari");
		guy2.beRepaired(2);
		guy2.guardGate();

		std::cout << std::endl
			<< "*Assigning guy4 the values of guy2 (Kari) using copy assignment operator*"
			<< std::endl;
		guy4 = guy2;
		std::cout << std::endl;

		guy4.attack("Jari");
		guy3.attack("Jari");
		guy1.takeDamage(30);
		guy1.beRepaired(15);
		guy1.attack("Kari");
		guy3.takeDamage(64);
		std::cout << std::endl;
	}

	{
		std::cout << std::endl
			<< "----Test 4: Running out of energy points----" << std::endl;
		ScavTrap	guy5("Pasi");
		ScavTrap	guy6("Masi");
		std::cout << std::endl;

		guy6.attack("Pasi");
		guy5.takeDamage(3);
		for (int i = 0; i < 48; i++)
		{
			guy5.attack("Masi");
			guy6.takeDamage(1);
		}
		guy5.beRepaired(1);
		guy5.attack("Masi");
		guy6.takeDamage(3);
		guy5.attack("Masi");
		guy5.guardGate();
		guy5.beRepaired(1);
		guy6.beRepaired(1);
		std::cout << std::endl;
	}

	return 0;
}
