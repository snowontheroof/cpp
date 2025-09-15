#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// std::cout << "Point: Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "Point: Initializing constructor called" << std::endl;
}

Point::Point(const Point& obj) : _x(obj.getX()), _y(obj.getY())
{
	// std::cout << "Point: Copy constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point: Destructor called" << std::endl;
}

const Fixed&	Point::getX() const
{
	return _x;
}

const Fixed&	Point::getY() const
{
	return _y;
}
