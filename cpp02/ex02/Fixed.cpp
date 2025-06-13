/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:36:13 by sojala            #+#    #+#             */
/*   Updated: 2025/06/13 18:07:16 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_FractBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;

	this->_RawBits = nbr * 256;
}

Fixed::Fixed(const float nbr) : _RawBits(nbr)
{
	std::cout << "Float constructor called" << std::endl;

	this->_RawBits = static_cast<int>(roundf(nbr * 256));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) : _RawBits(obj._RawBits)
{
	std::cout << "Copy constructor called" << std::endl;
	// *this = obj;	//why is this preferred in the subject output??
}

Fixed	&Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &f)
		this->_RawBits = f._RawBits;
	return (*this);
}

float	Fixed::toFloat(void) const
{
	float	tmp = _RawBits & 255;
	float	ret = _RawBits / 256;
	ret += tmp / 256;
	return (ret);
}

int	Fixed::toInt(void) const
{
	int	ret = _RawBits / 256;
	return (ret);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

int&	Fixed::min(int& fixedP1, int& fixedP2)
{
	if (fixedP1 < fixedP2)
		return (fixedP1);
	return (fixedP2);
}

const int&	Fixed::min(const int& fixedP1, const int& fixedP2)
{
	if (fixedP1 < fixedP2)
		return (fixedP1);
	return (fixedP2);
}

int&	Fixed::max(int& fixedP1, int& fixedP2)
{
	if (fixedP1 > fixedP2)
		return (fixedP1);
	return (fixedP2);
}

const int&	Fixed::max(const int& fixedP1, const int& fixedP2)
{
	if (fixedP1 > fixedP2)
		return (fixedP1);
	return (fixedP2);
}
