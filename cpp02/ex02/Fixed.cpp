/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:36:13 by sojala            #+#    #+#             */
/*   Updated: 2025/07/15 09:26:43 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractBits = 8;

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = nbr * 256;
}

Fixed::Fixed(const float nbr) : _rawBits(nbr)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = static_cast<int>(roundf(nbr * 256));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) : _rawBits(obj.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& other) const
{
	if (_rawBits > other.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (_rawBits < other.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (_rawBits >= other.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (_rawBits <= other.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (_rawBits == other.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	if (_rawBits != other.getRawBits())
		return true;
	else
		return false;
}

Fixed&	Fixed::operator++(void)
{
	_rawBits++;
	return *this;
}

Fixed&	Fixed::operator--(void)
{
	_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	_rawBits--;
	return tmp;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	_rawBits++;
	return tmp;
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = _rawBits + other.getRawBits();
	result.setRawBits(rawresult);
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = _rawBits - other.getRawBits();
	result.setRawBits(rawresult);
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = _rawBits * other.getRawBits();
	rawresult /= 256;
	result.setRawBits(rawresult);
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = _rawBits / other.getRawBits();
	rawresult *= 256;
	result.setRawBits(rawresult);
	return result;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
	return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
	return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
	return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
	return a;
	return b;
}

float	Fixed::toFloat(void) const
{
	float	tmp = _rawBits & 255;
	float	ret = _rawBits / 256;
	ret += tmp / 256;
	return ret;
}

int	Fixed::toInt(void) const
{
	int	ret = _rawBits / 256;
	return ret;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
