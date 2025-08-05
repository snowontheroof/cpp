/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:42:39 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 17:52:33 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat: Constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;
	WrongAnimal::operator=(other);
	if (this != &other)
		_type = "WrongCat";
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}
