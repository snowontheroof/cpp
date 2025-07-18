/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/07/18 11:43:02 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	{
		std::cout << "DiamondTrap: Hit points 100, energy points 50, attack damage 30"
			<< std::endl;
		std::cout << std::endl << "----Test 1: Simple test----" << std::endl;

		DiamondTrap	Markku("Markku");
		std::cout << std::endl
			<< "*Creating a copy of Markku using copy constructor*" << std::endl;
		DiamondTrap	Kerkko(Markku);
		std::cout << std::endl
			<< "*Creating Terttu with default constructor for later use*" << std::endl;
		DiamondTrap	Terttu;

		std::cout << std::endl
			<< "*Assigning Terttu the values of Markku using copy assignment operator*"
			<< std::endl;
		Terttu = Markku;
		std::cout << std::endl;

		Markku.whoAmI();
		Markku.highFivesGuys();
		Kerkko.whoAmI();
		Kerkko.guardGate();
		Terttu.whoAmI();
		Terttu.attack("Markku");
		Markku.takeDamage(99);
		Terttu.attack("Markku");
		Markku.takeDamage(3);
		Markku.beRepaired(2);
		Markku.whoAmI();
		Markku.guardGate();
		Markku.highFivesGuys();
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << "----Test 2----" << std::endl;
		DiamondTrap	guy1("Jari");
		DiamondTrap	guy2("Kari");
		std::cout << std::endl
			<< "*Creating a copy of guy2 (Kari) using copy constructor*" << std::endl;
		DiamondTrap	guy3(guy2);
		std::cout << std::endl
			<< "*Creating guy4 with default constructor for later use*" << std::endl;
		DiamondTrap	guy4;
		std::cout << std::endl;

		guy1.whoAmI();
		guy2.whoAmI();
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
		DiamondTrap	guy5("Pasi");
		DiamondTrap	guy6("Masi");
		std::cout << std::endl;

		guy6.attack("Pasi");
		guy5.takeDamage(3);
		for (int i = 0; i < 48; i++)
		{
			guy5.attack("Masi");
			guy6.takeDamage(2);
		}
		guy5.beRepaired(1);
		guy5.attack("Masi");
		guy6.takeDamage(3);
		guy5.attack("Masi");
		guy5.highFivesGuys();
		guy5.guardGate();
		guy5.beRepaired(1);
		guy6.beRepaired(1);
		std::cout << std::endl;
	}

	return 0;
}
