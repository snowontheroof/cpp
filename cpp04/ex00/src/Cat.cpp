/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:28 by sojala            #+#    #+#             */
/*   Updated: 2025/07/24 12:16:58 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	Animal::operator=(other);
	// if (this != &other)
	// 	type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!! Meouww!" << std::endl;
}
