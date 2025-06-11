/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:35:04 by sojala            #+#    #+#             */
/*   Updated: 2025/06/10 13:48:32 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl test;

	test.complain("DEBUG");
	test.complain("ERROR");
	test.complain("WHAT??");
	test.complain("WARNING");
	test.complain("INFO");
	return 0;
}

/*int	main(int argc, char **argv)
{
	Harl test;

	if (argc != 2)
		std::cout << "Expected usage: ./Harl DEBUG/INFO/WARNING/ERROR" << std::endl;
	else
		test.complain(argv[1]);
	return 0;
}*/
