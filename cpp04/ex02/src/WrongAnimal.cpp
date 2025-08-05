/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:42:36 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 17:52:37 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default WrongAnimal")
{
	std::cout << "WrongAnimal: Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : _type(obj._type)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

const std::string&	WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[ThIs Is NoT tHe RiGhT sTaNdArD aNiMaL sOuNd]" << std::endl;
}
