/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:35:56 by sojala            #+#    #+#             */
/*   Updated: 2025/07/15 10:41:23 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	try
	{
		Point	a(0, 0);
		Point	b(10, 0);
		Point	c(20, 6);
		Point	d(-2, 4);
		Point	point1(10, 2);
		Point	point2(0, 0);
		Point	point3(4, 0);
		Point	point4(3, -1);

		std::cout << bsp(a, b, c, point1) << std::endl;
		std::cout << bsp(a, b, c, point2) << std::endl;
		std::cout << bsp(a, b, c, point3) << std::endl;
		std::cout << bsp(b, c, d, point4) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
