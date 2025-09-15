#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# define FT_HP 100
# define FT_EP 100
# define FT_AD 30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& obj);
		FragTrap&	operator=(const FragTrap& other);
		~FragTrap();

		void	highFivesGuys(void);
};

#endif
