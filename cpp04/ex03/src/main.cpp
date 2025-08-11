/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:43:40 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/11 12:36:28 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl << "---- Trying to learn a fifth materia ----" << std::endl;
	AMateria*	test = new Ice();
	src->learnMateria(test);
	delete test;
	std::cout << std::endl << "---- Trying to learn a null materia ----" << std::endl;
	src->learnMateria(0);

	std::cout << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl << "---- Trying to equip a fifth slot ----" << std::endl;
	me->equip(tmp);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	std::cout << std::endl << "---- Trying to unequip at a nonexisting index ----" << std::endl;
	me->unequip(5);
	std::cout << std::endl << "---- Trying to create an invalid type materia ----" << std::endl;
	tmp = src->createMateria("what?");
	std::cout << std::endl << "---- Trying to equip with null ----" << std::endl;
	me->equip(0);

	std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	AMateria* temp;
	temp = src->createMateria("ice");
	me->equip(temp);
	temp = src->createMateria("cure");
	me->equip(temp);
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl << "---- Trying to use an unequipped slot ----" << std::endl;
	me->use(2, *bob);

	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}
