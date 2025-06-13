#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const int x_FP, const int y_FP) : x(x_FP), y(y_FP)
{
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

Point::~Point()
{
}
