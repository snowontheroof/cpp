#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug(void) const
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    return ;
}

void    Harl::info(void) const
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
        << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    return ;
}

void    Harl::warning(void) const
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl
        << "I’ve been coming for years whereas you started working here since last month." << std::endl;
    return ;
}

void    Harl::error(void) const
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    return ;
}

void    Harl::complain(std::string level)
{
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    // typedef void (Harl::*Ptr)();
    // Ptr array[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	void (Harl::*funcs[4])() const = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*funcs[i])();
            break ;
        }
    }
}
