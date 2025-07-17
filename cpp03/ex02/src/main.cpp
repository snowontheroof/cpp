/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/07/17 11:44:34 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		FragTrap	Marjatta("Marjatta");
		FragTrap	Teuvo("Teuvo");

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
	}

	{
		std::cout << std::endl << "----------------" << std::endl;
		ScavTrap	Liisa("Liisa");
		ScavTrap	Kaija("Kaija");

		Kaija.attack("Liisa");
		Liisa.takeDamage(20);
		Kaija.attack("Liisa");
		Liisa.takeDamage(20);
		Liisa.guardGate();
		Liisa.attack("Kaija");
		Kaija.takeDamage(20);
		Liisa.beRepaired(40);
	}

	return 0;
}
