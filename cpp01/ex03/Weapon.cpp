/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:34:30 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 11:10:45 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	std::cout << type << ": Constructor called" << std::endl;

	this->type = type;
	return ;
}
Weapon::~Weapon()
{
	std::cout << type << ": Destructor called" << std::endl;
	return ;
}

const std::string& Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
	return ;
}
