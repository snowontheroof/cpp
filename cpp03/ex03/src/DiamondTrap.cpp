/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:12:48 by sojala            #+#    #+#             */
/*   Updated: 2025/07/18 16:09:16 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name"), FragTrap(), ScavTrap(), _name("Unknown")
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
	std::cout << "DiamondTrap " << _name << ": Copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	if (this != &other)
		_name = other._name;
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
	if (_hitPoints == 0)
		std::cout << "DiamondTrap " << _name << " is already dead - we will never know its true identity..." << std::endl;
	else
		std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
