/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:35:56 by sojala            #+#    #+#             */
/*   Updated: 2025/07/14 16:24:22 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Fixed a(10);
		std::cout << a << std::endl;
		Fixed const b(2);
		std::cout << b << std::endl;
		Fixed const c(a * b);
		std::cout << c << std::endl;

		std::cout << "-----------------------" << std::endl;
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << "-----------------------" << std::endl;
		std::cout << b << std::endl;
		Fixed d(c / b);
		std::cout << d << std::endl;
		std::cout << d-- << std::endl;
		std::cout << d << std::endl;
		std::cout << --d << std::endl;

		std::cout << "-----------------------" << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << Fixed::min(b, c) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (d != c) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
