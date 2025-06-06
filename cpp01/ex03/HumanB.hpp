/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:34:17 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 11:10:05 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon& type);
};

#endif
