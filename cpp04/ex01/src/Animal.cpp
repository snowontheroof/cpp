/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:41:15 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:41:16 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : _type("Default")
{
	std::cout << "Animal " << _type << ": Constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) : _type(obj._type)
{
	std::cout << "Animal " << _type << ": Copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal " << _type << ": Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << ": Destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "[Standard animal sound]" << std::endl;
}
