/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:56:20 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 14:17:05 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	megaphone(std::string msg)
{
	for (int i = 0; msg[i]; i++)
		std::cout << static_cast<unsigned char>(std::toupper(msg[i]));
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			megaphone(argv[i]);
	}
	std::cout << std::endl;
	return 0;
}
