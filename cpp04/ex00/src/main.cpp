#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

const Animal *makeptr_without_new()
{
	const Animal* test;
	const Cat kissa;
	test = &kissa;
	return (test);
}

const Animal *makeptr_new_dog()
{
	const Animal* j = new Dog();
	return (j);
}

int	main(void)
{
	{
		std::cout << "---------Test 1---------" << std::endl;
		const Animal* j = makeptr_new_dog();
		const Animal* test;// = makeptr_without_new();
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
		std::cout << "* Copy assignment operator and copy constructor *" << std::endl;
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

		Dog	puppy;
		Dog musti(puppy);
		Dog laikku;
		laikku = puppy;

		std::cout << std::endl;
		std::cout << puppy.getType() << std::endl;
		std::cout << musti.getType() << std::endl;
		std::cout << laikku.getType() << std::endl;
		puppy.makeSound();
		musti.makeSound();
		laikku.makeSound();
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << "---------Test 3---------" << std::endl;
		std::cout << "* Test main provided in subject *" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;
		std::cout << meta->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl;
		const WrongAnimal *weird = new WrongAnimal();
		const WrongAnimal *odd = new WrongCat;
		WrongCat mysteryCat;

		std::cout << std::endl;
		std::cout << weird->getType() << std::endl;
		std::cout << odd->getType() << std::endl;
		std::cout << mysteryCat.getType() << std::endl;
		weird->makeSound();
		odd->makeSound();
		mysteryCat.makeSound();

		std::cout << std::endl;
		delete	meta;
		delete	j;
		delete	i;
		delete	weird;
		delete	odd;
	}

	return 0;
}
