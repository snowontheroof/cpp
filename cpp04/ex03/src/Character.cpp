#include "Character.hpp"

Character::Character() : name("Default")
{
	std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(std::string name) : name(name)
{
	std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(const Character& obj) : name(obj.name)
{
	std::cout << "Character: Copy constructor called" << std::endl;
}

Character&	Character::operator=(const Character& other)
{
	std::cout << "Character: Copy assignment operator called" << std::endl;
	if (this != &other)
		name = other.name;
	return *this;
}

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
}

const std::string&	Character::getName() const
{
	return name;
}

void	equip(AMateria* m)
{

}

void	unequip(int indx)
{

}

void	use(int idx, ICharacter& target)
{

}
