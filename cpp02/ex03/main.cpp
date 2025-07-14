/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:35:56 by sojala            #+#    #+#             */
/*   Updated: 2025/07/14 15:58:42 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

int main(void)
{
	try
	{
		Point	a(0, 0);
		Point	b(10, 30);
		Point	c(20, 0);
		Point	point(30, 15);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
