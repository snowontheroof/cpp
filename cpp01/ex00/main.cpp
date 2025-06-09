/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:33:18 by sojala            #+#    #+#             */
/*   Updated: 2025/06/09 18:11:47 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	Kimmo("Kimmo");
	Kimmo.announce();

	Zombie*	Tero = newZombie("Tero");
	Tero->announce();
	delete (Tero);

	randomChump("Markku");
	return 0;
}
