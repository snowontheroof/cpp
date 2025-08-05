/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:43:16 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:43:17 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria " << _type << ": Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj) : _type(obj._type)
{
	std::cout << "AMateria " << _type << ": Copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria " << _type << ": Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria " << _type << ": Destructor called" << std::endl;
}

const std::string&	AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	if (_type.empty())
		std::cout << "Materia type not set" << std::endl;
}
