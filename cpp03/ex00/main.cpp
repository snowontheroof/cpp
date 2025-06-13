/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/06/12 12:02:44 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	guy1("guy1");
	ClapTrap	guy2("guy2");

	guy1.attack("guy2");
	guy2.takeDamage(8);
	guy2.attack("guy1");
	guy1.takeDamage(4);
	guy1.attack("guy2");
	guy2.takeDamage(3);
	guy2.attack("guy1");
	guy2.beRepaired(2);
}
