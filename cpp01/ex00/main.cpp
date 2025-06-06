/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:33:18 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 11:15:40 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	Kimmo("Kimmo");
	Kimmo.announce();

	Zombie*	Tero = newZombie("Tero");
	Tero->announce();
	delete (Tero);

	randomChump("Markku");
	return 0;
}
