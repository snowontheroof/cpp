#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA {
	private:
		std::string	_myName;
		Weapon		_myWeapon;
	public:
		HumanA();
		HumanA(std::string name, Weapon weapon);
		~HumanA();

		void	attack();
};

#endif
