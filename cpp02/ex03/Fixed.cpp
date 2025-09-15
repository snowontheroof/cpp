#include "Fixed.hpp"

const int	Fixed::_fractBits = 8;

Fixed::Fixed() : _rawBits(0)
{
	// std::cout << "Fixed: Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	// std::cout << "Fixed: Int constructor called" << std::endl;
	_rawBits = nbr * 256;
}

Fixed::Fixed(const float nbr) : _rawBits(nbr)
{
	// std::cout << "Fixed: Float constructor called" << std::endl;
	_rawBits = static_cast<int>(roundf(nbr * 256));
}

Fixed::~Fixed()
{
	// std::cout << "Fixed: Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) : _rawBits(obj.getRawBits())
{
	// std::cout << "Fixed: Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	// std::cout << "Fixed: Copy assignment operator called" << std::endl;

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

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	_rawBits++;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	_rawBits--;
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
	if (a < b)
		return a;
	else
		return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
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

int		Fixed::getRawBits(void) const
{
	// std::cout << "Fixed: getRawBits member function called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "Fixed: setRawBits member function called" << std::endl;
	_rawBits = raw;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
