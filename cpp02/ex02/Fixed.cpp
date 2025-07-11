/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:36:13 by sojala            #+#    #+#             */
/*   Updated: 2025/07/11 16:51:46 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_FractBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;

	this->_RawBits = 0;
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

Fixed&	Fixed::operator=(const Fixed& f)
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

	return (this->_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

Fixed	Fixed::operator++(void) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = this->_RawBits + 1;
	result.setRawBits(rawresult);
	return (result);
}

Fixed	Fixed::operator--(void) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = this->_RawBits - 1;
	result.setRawBits(rawresult);
	return (result);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = this->_RawBits + other.getRawBits();
	result.setRawBits(rawresult);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = this->_RawBits - other.getRawBits();
	result.setRawBits(rawresult);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = this->_RawBits * other.getRawBits();
	rawresult = rawresult >> _FractBits;
	result.setRawBits(rawresult);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed		result;
	long long	rawresult;

	rawresult = this->_RawBits / other.getRawBits();
	rawresult = rawresult << _FractBits;
	result.setRawBits(rawresult);
	return (result);
}
