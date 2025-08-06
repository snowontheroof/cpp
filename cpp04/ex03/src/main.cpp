/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:43:40 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/06 17:11:51 by sojala           ###   ########.fr       */
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
	IMateriaSource* test = new MateriaSource();
	test->learnMateria(new Ice());
	test->learnMateria(new Cure());
	test->learnMateria(new Ice());
	test->learnMateria(new Cure());

	ICharacter* first = new Character("first");
	first->equip(test->createMateria("ice"));
	first->equip(test->createMateria("ice"));
	first->equip(test->createMateria("ice"));
	first->equip(test->createMateria("ice"));
	first->unequip(0);
	first->unequip(3);
	first->unequip(1);
	first->unequip(2);
	first->equip(test->createMateria("cure"));
	first->equip(test->createMateria("cure"));
	first->equip(test->createMateria("cure"));
	first->equip(test->createMateria("cure"));
	first->unequip(0);
	first->unequip(3);
	first->unequip(1);
	first->unequip(2);

	delete first;
	delete test;

	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// me->equip(tmp);
	// me->unequip(1);
	// me->unequip(2);
	// me->unequip(3);

	// ICharacter* uusi(me);
	// uusi->unequip(0);

	// ICharacter* bob = new Character("bob");
	// AMateria* temp;
	// temp = src->createMateria("ice");
	// me->equip(temp);
	// temp = src->createMateria("cure");
	// me->equip(temp);
	// std::cout << std::endl;

	// me->use(0, *bob);
	// me->use(1, *bob);

	// std::cout << std::endl;
	// delete bob;
	// delete me;
	// delete src;

	return 0;
}
