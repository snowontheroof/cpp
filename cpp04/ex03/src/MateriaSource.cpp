/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:43:43 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:43:44 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: Default constructor called" << std::endl;
	for (int i = 0; i < STORAGE_MAX; i++)
		_storage[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	for (int i = 0; i < STORAGE_MAX; i++)
	{
		if (obj._storage[i])
			_storage[i] = obj._storage[i]->clone();
		else
			_storage[i] = nullptr;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < STORAGE_MAX; i++)
		{
			if (_storage[i])
			{
				delete _storage[i];
				if (other._storage[i])
					_storage[i] = other._storage[i]->clone();
				else
					_storage[i] = nullptr;
			}
		}
	}
	return *this ;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < STORAGE_MAX; i++)
	{
		if (_storage[i])
			delete _storage[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "Error: No Materia to learn!" << std::endl;
		return ;
	}
	for (int i = 0; i < STORAGE_MAX; i++)
	{
		if (!_storage[i])
		{
			_storage[i] = m->clone();
			return ;
		}
	}
	std::cout << "Error: The storage is already full!" << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	AMateria*	tmp = nullptr;
	for (int i = 0; _storage[i]; i++)
	{
		if (type == _storage[i]->getType())
		{
			tmp = _storage[i]->clone();
			return tmp;
		}
	}
	std::cout << "Error: Unknown type, no matching Materia template" << std::endl;
	return tmp;
}
