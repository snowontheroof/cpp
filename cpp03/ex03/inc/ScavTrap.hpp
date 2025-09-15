#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# define ST_HP 100
# define ST_EP 50
# define ST_AD 20

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& obj);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap();

		void	attack(const std::string& target) override;
		void	guardGate();
};

#endif
