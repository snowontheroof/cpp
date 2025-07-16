/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/07/16 16:07:27 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	guy1("Jari");
	ClapTrap	guy2("Kari");
	std::cout << "< Creating a copy of guy2 (Kari) using copy constructor: >" << std::endl;
	ClapTrap	guy3(guy2);
	ClapTrap	guy4;

	guy1.attack("Lari");
	guy2.takeDamage(8);
	guy2.attack("Jari");
	guy1.takeDamage(4);
	guy1.attack("Kari");
	guy2.takeDamage(3);
	guy2.attack("Jari");
	guy2.beRepaired(2);

	std::cout << std::endl << "--------------------" << std::endl
		<< "< Assigning guy4 the values of guy2 (Kari) using copy assignment operator: >"
		<< std::endl;
	guy4 = guy2;
	guy4.attack("Jari");
	guy3.attack("Jari");
	guy1.takeDamage(3);
	guy1.beRepaired(1);
	guy1.attack("Kari");
	guy3.takeDamage(14);

	return 0;
}
