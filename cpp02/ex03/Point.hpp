#ifndef	POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"
# include <iostream>

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		Point(const int x_FP, const int y_FP);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		const Fixed&	getX();
		const Fixed&	getY();
};

#endif
