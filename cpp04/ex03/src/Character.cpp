#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Default")
{
	std::cout << "Character " << _name << ": Constructor called" << std::endl;
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
	t_Node*	curr = obj._first;
	t_Node*	my_curr = _first;
	while (curr)
	{
		my_curr = new t_Node;
		my_curr->_content = curr->_content->clone();
		my_curr->_next = curr->_next;
		curr = curr->_next;
		my_curr = my_curr->_next;
	}
}

Character&	Character::operator=(const Character& other)
{
	std::cout << "Character " << _name << ": Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < INVENTORY_MAX; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
		if (!other._first)
		{
			_first = nullptr;
			return *this;
		}
		t_Node*	curr = other._first;
		t_Node*	my_curr = _first;
		while (curr)
		{
			my_curr = new t_Node;
			my_curr->_content = curr->_content->clone();
			my_curr->_next = curr->_next;
			curr = curr->_next;
			my_curr = my_curr->_next;
		}
		_name = other._name;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character " << _name << ": Destructor called" << std::endl;
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	t_Node*	curr;
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
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Error: Cannot equip - the inventory is already full!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !_inventory[idx])
	{
		std::cout << "Error: Cannot unequip - index " << idx
			<< " is out of bounds!" << std::endl;
		return ;
	}
	if (_first)
	{
		t_Node* curr = _first;
		while (curr->_next)
			curr = curr->_next;
		curr->_next = new t_Node;
		curr->_next->_content = _inventory[idx];
		curr->_next->_next = nullptr;
	}
	else
	{
		_first = new t_Node;
		_first->_content = _inventory[idx];
		_first->_next = nullptr;
	}
	_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	if (!_inventory[idx])
	{
		std::cout << "Error: No materia to use at index " << idx
			<< "!" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
