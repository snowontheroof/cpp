/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:12:33 by sojala            #+#    #+#             */
/*   Updated: 2025/07/18 11:54:52 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	_hitPoints =  ST_HP;
	_energyPoints = ST_EP;
	_attackDamage = ST_AD;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << ": Constructor called" << std::endl;
	_hitPoints =  ST_HP;
	_energyPoints = ST_EP;
	_attackDamage = ST_AD;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap " << _name << ": Copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _name << ": Copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << ": Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack - it is already dead!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " doesn't have enough energy to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage
		<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " cannot activate Gate keeper mode - it is already dead!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " doesn't have enough energy to gatekeep!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	_energyPoints--;
}
