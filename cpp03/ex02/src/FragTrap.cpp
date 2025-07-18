/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:12:21 by sojala            #+#    #+#             */
/*   Updated: 2025/07/18 11:54:21 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << ": Constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	std::cout << "FragTrap " << _name << ": Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << ": Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << ": Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name
			<< " cannot give any high fives - it is already dead!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name
			<< " does not have the energy high fives would take!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << ": high five, guys!! Wohoo!!" << std::endl;
	_energyPoints--;
}
