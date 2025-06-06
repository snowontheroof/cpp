/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:34:59 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 14:26:01 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	return ;
}

void    Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl
		<< "I've been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	typedef		void (Harl::*func)();
	func			array[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	int			i;

	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*array[i])();
			break ;
		}
	}
	if (i == 4)
		std::cout << "I would love to complain about something, but it seems there's nothing left! It's intolerable."
			<< std::endl;
}
