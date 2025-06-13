/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:48 by sojala            #+#    #+#             */
/*   Updated: 2025/06/13 10:25:51 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap " << name << ": Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << ": Constructor called" << std::endl;

	this->name = name;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << ": Destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack - they are already dead!" << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name
			<< " cannot attack - not enough energy points!" << std::endl;
		return ;
	}
	energyPoints -= 1;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage
		<< " points of damage!" << std::endl;
	//does Damage have to be taken in here?
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already dead. Don't try to hurt them anymore!" << std::endl;
		return ;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is now dead. Too bad!" << std::endl;
	else
		std::cout << "ClapTrap " << name << " now has " << hitPoints << " hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " cannot repair itself - they are already dead!" << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name
			<< " cannot repair itself - not enough energy points!" << std::endl;
		return ;
	}
	energyPoints -= 1;
	hitPoints += amount;
	std::cout << "ClapTrap " << name
		<< " repaired itself and now has " << hitPoints << " hit points!" << std::endl;
}
