/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:33:33 by sojala            #+#    #+#             */
/*   Updated: 2025/06/11 09:43:18 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	try
	{
		Zombie*	bunch = zombieHorde(8, "Jouni");

		for (int i = 0; i < 8; i++)
			bunch[i].announce();
		bunch[0].setName("Markku");
		for (int i = 0; i < 8; i++)
			bunch[i].announce();
		delete[] bunch;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
