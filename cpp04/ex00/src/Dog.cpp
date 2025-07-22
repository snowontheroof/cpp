/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:32 by sojala            #+#    #+#             */
/*   Updated: 2025/07/22 10:09:48 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	Animal::operator=(other);
	// if (this != &other)
	// 	type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof, woof!! Bark!" << std::endl;
}
