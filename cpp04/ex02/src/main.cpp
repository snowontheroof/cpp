/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:42:32 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/11 13:13:21 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int	main(void)
{
	{
		std::cout << "---------Test 1---------" << std::endl;
		AAnimal* array[10];
		for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				array[i] = new Cat();
			else
				array[i] = new Dog();
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << std::endl << array[i]->getType() << std::endl;
			array[i]->makeSound();
		}
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete array[i];
	}

	/*{
		std::cout << std::endl << "---------Trying to instantiate an abstract class---------" << std::endl;
		AAnimal	test;	//making an AAnimal object (instead of a pointer) will not compile!
	}*/

	{
		std::cout << std::endl << "---------Test 2---------" << std::endl;
		std::cout << "* Copy constructor and copy assignment operator *" << std::endl;
		Dog koira;
		Dog	pentu(koira);

		std::cout << std::endl << koira.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl << pentu.getBrain()->getIdea(0) << std::endl;
		koira.getBrain()->setIdea(84, "Who let the dogs out?");
		std::cout << std::endl << koira.getBrain()->getIdea(84) << std::endl;
		std::cout << std::endl << pentu.getBrain()->getIdea(84) << std::endl << std::endl;

		Dog	musti;
		musti = koira;
		std::cout << std::endl << musti.getBrain()->getIdea(84) << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << "---------Test 3---------" << std::endl;
		const Dog	puppy;

		std::cout << std::endl << puppy.getBrain()->getIdea(3) << std::endl;
		puppy.getBrain()->setIdea(3, "Should we get some bones??");
		std::cout << std::endl << puppy.getBrain()->getIdea(3) << std::endl;
		std::cout << std::endl << puppy.getBrain()->getIdea(103) << std::endl;
		puppy.getBrain()->setIdea(-2, "Is this a good idea?");
		std::cout << std::endl;
	}

	return 0;
}
