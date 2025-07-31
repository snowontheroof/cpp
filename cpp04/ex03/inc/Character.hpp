#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria*	inventory[4];

	public:
		Character();
		Character(std::string name);
		Character(const Character& obj);
		Character&	operator=(const Character& other);
		~Character();

		const std::string&	getName() const;

		void				equip(AMateria* m);
		void				unequip(int indx);
		void				use(int idx, ICharacter& target);
};

#endif
