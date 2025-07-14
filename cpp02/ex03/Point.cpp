#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const int x, const int y) : _x(x), _y(y)
{
}

Point::Point(const Point& obj) : _x(obj._x), _y(obj._y)
{
}

Point::~Point()
{
}

const Fixed&	Point::getX() const
{
	return (_x);
}

const Fixed&	Point::getY() const
{
	return (_y);
}
