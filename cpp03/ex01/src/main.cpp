/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/07/16 13:47:27 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
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
	Martin.beRepaired(2);

	return 0;
}
