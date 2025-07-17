/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:55 by sojala            #+#    #+#             */
/*   Updated: 2025/07/17 16:26:20 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	FragTrap	Tere("Tere");
	FragTrap	Moro(Tere);

	DiamondTrap	Markku("Markku");
	DiamondTrap	Kerkko(Markku);
	DiamondTrap	Terttu;

	Terttu = Markku;
	Markku.whoAmI();
	Kerkko.whoAmI();
	Terttu.whoAmI();

	return 0;
}
