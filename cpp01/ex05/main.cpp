/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:35:04 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 14:07:15 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl test;

	if (argc != 2)
		std::cout << "Expected usage: ./Harl DEBUG/INFO/WARNING/ERROR" << std::endl;
	else
		test.complain(argv[1]);
	return 0;
}
