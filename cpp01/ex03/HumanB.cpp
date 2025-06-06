/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:34:13 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 11:10:01 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << name << ": Constructor called" << std::endl;

	this->name = name;
	return ;
}

HumanB::~HumanB()
{
	std::cout << name << ": Destructor called" << std::endl;
	return ;
}

void	HumanB::attack() const
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& type)
{
	this->weapon = &type;
	return ;
}
