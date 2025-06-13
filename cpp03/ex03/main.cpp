/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/06/13 10:39:28 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Joe("Joe");
	ScavTrap	Martin("Martin");

	Joe.attack("Martin");
	Martin.takeDamage(8);
	Martin.attack("Joe");
	Joe.takeDamage(4);
	Joe.attack("Martin");
	Martin.takeDamage(3);
	Martin.attack("Joe");
	Martin.beRepaired(2);
}
