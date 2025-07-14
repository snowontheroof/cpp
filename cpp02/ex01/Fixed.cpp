/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:36:13 by sojala            #+#    #+#             */
/*   Updated: 2025/07/14 15:07:14 by sojala           ###   ########.fr       */
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
	_RawBits = nbr * 256;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	_RawBits = static_cast<int>(roundf(nbr * 256));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) : _RawBits(obj._RawBits)
{
	std::cout << "Copy constructor called" << std::endl;
	// *this = obj;	//why is this preferred in the subject output??
	// it would then call the copy assignment operator
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_RawBits = other._RawBits;
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_RawBits = raw;
}
