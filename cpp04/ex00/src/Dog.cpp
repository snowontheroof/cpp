/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:32 by sojala            #+#    #+#             */
/*   Updated: 2025/08/05 17:25:06 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog: Constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
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
