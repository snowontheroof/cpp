/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:33:37 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 10:41:31 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A generic Zombie: Constructor called" << std::endl;

	this->name = "A generic Zombie";
	return ;
}

Zombie::Zombie(std::string name)
{
	std::cout << name << ": Constructor called" << std::endl;

	this->name = name;
	return ;
}

Zombie::~Zombie()
{
	std::cout << name << ": Destructor called" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
