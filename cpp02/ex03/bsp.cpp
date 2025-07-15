/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:16:20 by sojala            #+#    #+#             */
/*   Updated: 2025/07/15 13:16:21 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float	findArea(Point const a, Point const b, Point const c)
{
	float	x1 = (a.getX()).toFloat();
	float	y1 = (a.getY()).toFloat();
	float	x2 = (b.getX()).toFloat();
	float	y2 = (b.getY()).toFloat();
	float	x3 = (c.getX()).toFloat();
	float	y3 = (c.getY()).toFloat();

	return fabs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2);
}

bool	isVertex(Point const a, Point const b, Point const c, Point const point)
{
	if ((point.getX() == a.getX() && point.getY() == a.getY())
		|| (point.getX() == b.getX() && point.getY() == b.getY())
		|| (point.getX() == c.getX() && point.getY() == c.getY()))
		return true;
	else
		return false;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	triangleArea;
	float	pointArea1;
	float	pointArea2;
	float	pointArea3;

	if (isVertex(a, b, c, point))
		return false;

	triangleArea = findArea(a, b, c);
	pointArea1 = findArea(point, b, c);
	pointArea2 = findArea(a, point, c);
	pointArea3 = findArea(a, b, point);

	if (pointArea1 == 0 || pointArea2 == 0 || pointArea3 == 0)
		return false;

	if (triangleArea == (pointArea1 + pointArea2 + pointArea3))
		return true;
	else
		return false;
}
