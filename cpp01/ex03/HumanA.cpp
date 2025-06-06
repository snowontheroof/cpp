/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:34:02 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 11:07:48 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout << name << ": Constructor called" << std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << name << ": Destructor called" << std::endl;
	return ;
}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
