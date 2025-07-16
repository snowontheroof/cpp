/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/07/16 13:58:39 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Joe("Joe");
	FragTrap	Martin("Martin");

	Joe.attack("Martin");
	Martin.takeDamage(8);
	Martin.attack("Joe");
	Joe.takeDamage(4);
	Joe.attack("Martin");
	Martin.takeDamage(3);
	Martin.attack("Joe");
	Martin.beRepaired(2);
}
