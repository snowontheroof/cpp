/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:35 by sojala            #+#    #+#             */
/*   Updated: 2025/07/22 11:19:07 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// const Animal *makeptr2()
// {
// 	const Animal* test;
// 	const Cat kissa;
// 	test = &kissa;
// 	return (test);
// }

// const Animal *makeptr()
// {
// 	const Animal* j = new Dog();
// 	return (j);
// }

int	main(void)
{
	// const Animal* j = makeptr();
	// const Animal* test = makeptr2();

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
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

	return 0;
}
