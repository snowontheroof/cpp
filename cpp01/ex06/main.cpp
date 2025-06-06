/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:35:17 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 14:27:57 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	letsHarl;

	if (argc != 2)
		std::cout << "Expected usage: ./harlFilter DEBUG/INFO/WARNING/ERROR" << std::endl;
	else
		letsHarl.complain(argv[1]);
	return 0;
}
