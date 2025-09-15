#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "FragTrap: Hit points 100, energy points 100, attack damage 30"
			<< std::endl << std::endl;
		std::cout << "----Test 1: Basic test----" << std::endl;
		FragTrap	Marjatta("Marjatta");
		FragTrap	Teuvo("Teuvo");
		std::cout << std::endl;

		Marjatta.attack("Teuvo");
		Teuvo.takeDamage(30);
		Marjatta.attack("Teuvo");
		Teuvo.takeDamage(30);
		Teuvo.attack("Marjatta");
		Marjatta.takeDamage(30);
		Marjatta.beRepaired(1);
		Teuvo.attack("Marjatta");
		Marjatta.takeDamage(30);
		Marjatta.highFivesGuys();
		Teuvo.highFivesGuys();
		Teuvo.attack("Marjatta");
		Teuvo.attack("Marjatta");
		Marjatta.takeDamage(60);
		Marjatta.highFivesGuys();
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << "----Test 2----" << std::endl;
		FragTrap	guy1("Jari");
		FragTrap	guy2("Kari");
		std::cout << std::endl
			<< "*Creating a copy of guy2 (Kari) using copy constructor*" << std::endl;
		FragTrap	guy3(guy2);
		std::cout << std::endl
			<< "*Creating guy4 with default constructor for later use*" << std::endl;
		FragTrap	guy4;
		std::cout << std::endl;

		guy1.attack("Lari");
		guy2.takeDamage(80);
		guy2.attack("Jari");
		guy1.takeDamage(14);
		guy1.attack("Kari");
		guy2.takeDamage(23);
		guy2.attack("Jari");
		guy2.beRepaired(2);
		guy2.highFivesGuys();

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
			<< "----Test 3: Running out of energy points----" << std::endl;
		FragTrap	guy5("Pasi");
		FragTrap	guy6("Masi");
		std::cout << std::endl;

		guy6.attack("Pasi");
		guy5.takeDamage(3);
		for (int i = 0; i < 98; i++)
		{
			guy5.attack("Masi");
			guy6.takeDamage(1);
		}
		guy5.beRepaired(1);
		guy5.attack("Masi");
		guy6.takeDamage(3);
		guy5.attack("Masi");
		guy5.highFivesGuys();
		guy5.beRepaired(1);
		guy6.beRepaired(1);
		std::cout << std::endl;
	}

	return 0;
}
