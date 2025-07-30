#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (obj.storage[i])
			storage[i] = obj.storage[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!storage[i])
		{
			storage[i] = m->clone();
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	AMateria*	tmp = nullptr;
	for (int i = 0; i < 4; i++)
	{
		if (type == storage[i]->getType())
		{
			tmp = storage[i]->clone();
			break ;
		}
	}
	return tmp;
}
