/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:16:05 by sojala            #+#    #+#             */
/*   Updated: 2025/07/15 15:28:25 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"
# include <iostream>

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& obj);
		Point& operator=(const Point& other) = delete;
		~Point();

		const Fixed&	getX() const;
		const Fixed&	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
