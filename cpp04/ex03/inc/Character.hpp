#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# define INVENTORY_MAX 4

typedef struct s_Nodes
{
	AMateria*		_content;
	struct s_Nodes*	_next;
}					t_Nodes;

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		t_Nodes*	_first;

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
