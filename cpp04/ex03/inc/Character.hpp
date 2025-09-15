#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# define INVENTORY_MAX 4
# include "AMateria.hpp"

typedef struct s_Node
{
	AMateria*		_content;
	struct s_Node*	_next;
}					t_Node;

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		t_Node*		_first;

	public:
		Character();
		Character(std::string name);
		Character(const Character& obj);
		Character&	operator=(const Character& other);
		~Character();

		const std::string&	getName() const;

		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
