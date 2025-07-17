/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/07/17 15:53:04 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	{
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
	}

	{
		std::cout << std::endl << "----------------------" << std::endl;
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
	}

	return 0;
}
