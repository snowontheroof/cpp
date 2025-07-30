/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:35 by sojala            #+#    #+#             */
/*   Updated: 2025/07/30 15:38:18 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

const Animal *makeptr2()
{
	const Animal* test;
	const Cat kissa;
	test = &kissa;
	return (test);
}

const Animal *makeptr()
{
	const Animal* j = new Dog();
	return (j);
}

int	main(void)
{
	{
		std::cout << "---------Test 1---------" << std::endl;
		const Animal* j = makeptr();
		const Animal* test;// = makeptr2();
		const Cat kissa;
		const Dog koira;
		test = &kissa;

		std::cout << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << test->getType() << std::endl;
		j->makeSound();
		test->makeSound();

		std::cout << std::endl;
		test = &koira;
		test->makeSound();
		std::cout << std::endl;
		delete j;
	}

	{
		std::cout << std::endl << "---------Test 2---------" << std::endl;
		Animal a;
		Animal b;
		b = a;
		Animal c(a);

		std::cout << std::endl;
		std::cout << a.getType() << std::endl;
		std::cout << b.getType() << std::endl;
		std::cout << c.getType() << std::endl;
		a.makeSound();
		b.makeSound();
		c.makeSound();
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << "---------Test 3---------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl;
		const WrongAnimal *weird = new WrongAnimal();
		const WrongAnimal *odd = new WrongCat;

		std::cout << std::endl;
		std::cout << weird->getType() << std::endl;
		std::cout << odd->getType() << std::endl;
		weird->makeSound();
		odd->makeSound();

		std::cout << std::endl;
		delete	meta;
		delete	j;
		delete	i;
		delete	weird;
		delete	odd;
	}

	return 0;
}
