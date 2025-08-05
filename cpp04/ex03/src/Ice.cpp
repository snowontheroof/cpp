/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:43:29 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 17:52:15 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice: Constructor called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice& obj) : AMateria(obj)
{
	std::cout << "Ice: Copy constructor called" << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	std::cout << "Ice: Copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice: Destructor called" << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria*	tmp = new Ice();
	return tmp;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
