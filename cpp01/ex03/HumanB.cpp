/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:34:13 by sojala            #+#    #+#             */
/*   Updated: 2025/06/11 09:57:48 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr)
{
	std::cout << name << ": HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << name << ": HumanB destructor called" << std::endl;
}

void	HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " cannot attack without a weapon!" << std::endl;
}

void	HumanB::setWeapon(Weapon& type)
{
	this->weapon = &type;
}
