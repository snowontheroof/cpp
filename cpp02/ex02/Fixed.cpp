/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:36:13 by sojala            #+#    #+#             */
/*   Updated: 2025/07/14 15:08:31 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_FractBits = 8;

Fixed::Fixed() : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	_RawBits = nbr * 256;
}

Fixed::Fixed(const float nbr) : _RawBits(nbr)
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
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_RawBits = other._RawBits;
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
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

bool	Fixed::operator>(const Fixed& other) const
{
	if (getRawBits() > other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (getRawBits() < other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (getRawBits() >= other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (getRawBits() <= other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (getRawBits() == other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	if (getRawBits() != other.getRawBits())
		return (true);
	else
		return (false);
}

Fixed&	Fixed::operator++(void)
{
	_RawBits++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	_RawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	_RawBits--;
	return (tmp);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	_RawBits++;
	return (tmp);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = _RawBits + other.getRawBits();
	result.setRawBits(rawresult);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = _RawBits - other.getRawBits();
	result.setRawBits(rawresult);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = _RawBits * other.getRawBits();
	rawresult /= 256;
	result.setRawBits(rawresult);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = _RawBits / other.getRawBits();
	rawresult *= 256;
	result.setRawBits(rawresult);
	return (result);
}
