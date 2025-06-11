/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:48 by sojala            #+#    #+#             */
/*   Updated: 2025/06/10 14:38:29 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << name << ": Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << name << ": Constructor called" << std::endl;

	this->name = name;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << name << ": Destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage
		<< " points of damage!" << std::endl;

	takeDamage(attackDamage);
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{

}
