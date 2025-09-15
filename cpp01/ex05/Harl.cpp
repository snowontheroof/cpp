#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
		<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void    Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I'm a regular here!" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	typedef		void (Harl::*funcs)();
	funcs		array[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
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
