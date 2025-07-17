/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:12:48 by sojala            #+#    #+#             */
/*   Updated: 2025/07/17 16:49:30 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*DO YOU UNDERSTAND EVERYTHING THAT HAPPENS HERE !! WHY DO WE CALL DIFFERENT CONSTRUCTORS
AND SET THE VALUES MANUALLY?? WHY DO WE DO IT DIFFERENTLY IN OTHER DERIVED CLASSES
IE FRAG AND SCAV???*/

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name"), FragTrap("Unknown"), ScavTrap("Unknown"), _name("Unknown")
{
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
	_hitPoints = FT_HP;
	_energyPoints = ST_EP;
	_attackDamage = FT_AD;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap " << _name << ": Constructor called" << std::endl;
	_hitPoints = FT_HP;
	_energyPoints = ST_EP;
	_attackDamage = FT_AD;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj._name + "_clap_name"), FragTrap(obj), ScavTrap(obj), _name(obj._name)
{
	std::cout << "DiamondTrap " << _name << ": Copy constructor called" << std::endl;
	_hitPoints = FT_HP;
	_energyPoints = ST_EP;
	_attackDamage = FT_AD;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "DiamondTrap " << _name << ": Copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << ": Destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
