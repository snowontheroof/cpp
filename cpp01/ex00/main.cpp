/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:33:18 by sojala            #+#    #+#             */
/*   Updated: 2025/06/11 09:41:52 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	try
	{
		Zombie	Kimmo("Kimmo");
		Kimmo.announce();

		Zombie*	Tero = newZombie("Tero");
		Tero->announce();
		delete (Tero);

		randomChump("Markku");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
