/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:41:28 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 17:42:35 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat: Constructor called" << std::endl;
	_type = "Cat";
	_myBrain = new Brain();
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	_myBrain = new Brain(*obj._myBrain);
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _myBrain;
		_myBrain = new Brain(*other._myBrain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete _myBrain;
}

Brain*	Cat::getBrain() const
{
	return _myBrain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!! Meouww!" << std::endl;
}
