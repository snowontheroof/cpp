#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Default")
{
	std::cout << "Character: Default constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_MAX; i++)
		_inventory[i] = nullptr;
	_first = nullptr;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character " << _name << ": Constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_MAX; i++)
		_inventory[i] = nullptr;
	_first = nullptr;
}

Character::Character(const Character& obj) : _name(obj._name)
{
	std::cout << "Character " << _name << ": Copy constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		if (obj._inventory[i])
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	if (!obj._first)
	{
		_first = nullptr;
		return ;
	}
	t_Nodes*	curr = obj._first;
	while (curr)
	{
		_first = new t_Nodes;
		_first->_content = curr->_content->clone();
		_first->_next = curr->_next;
		curr = curr->_next;
	}
}

Character&	Character::operator=(const Character& other)
{
	std::cout << "Character: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < INVENTORY_MAX; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				if (other._inventory[i])
					_inventory[i] = other._inventory[i]->clone();
				else
					_inventory[i] = nullptr;
			}
		}
		if (!other._first)
		{
			_first = nullptr;
			return *this;
		}
		t_Nodes*	curr = other._first;
		while (curr)
		{
			_first = new t_Nodes;
			_first->_content = curr->_content->clone();
			_first->_next = curr->_next;
			curr = curr->_next;
		}
		_name = other._name;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	t_Nodes*	curr;
	while (_first)
	{
		curr = _first->_next;
		delete _first->_content;
		delete _first;
		_first = curr;
	}
	_first = nullptr;
}

const std::string&	Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Error: No materia to equip with!" << std::endl;
		return ;
	}
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Error: The _inventory is already full!" << std::endl;
}

void	Character::unequip(int indx)
{
	if (!(indx >= 0 && indx < 3))
	{
		std::cout << "Error: index out of bounds" << std::endl;
		return ;
	}
	t_Nodes* curr = _first;
	while (curr->_next)
		curr = curr->_next;
	curr->_next = new t_Nodes;
	curr->_next->_content = _inventory[indx];
	curr->_next->_next = nullptr;	
	_inventory[indx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	_inventory[idx]->use(target);
}
