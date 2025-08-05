/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:43:25 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:43:26 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure: Default constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure& obj) : AMateria(obj)
{
	std::cout << "Cure: Copy constructor called" << std::endl;
}

Cure&	Cure::operator=(const Cure& other)
{
	std::cout << "Cure: Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure: Destructor called" << std::endl;
}

AMateria*	Cure::clone() const
{
	AMateria*	tmp = new Cure();
	return tmp;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
