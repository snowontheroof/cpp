/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:42:16 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:42:17 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Default")
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) : _type(obj._type)
{
	std::cout << "AAnimal: Copy constructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal: Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return _type;
}
