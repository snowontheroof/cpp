/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:33:33 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 10:44:14 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	bunch = zombieHorde(8, "Markku");

	for (int i = 0; i < 8; i++)
		bunch[i].announce();
	delete[] bunch;
	return 0;
}
