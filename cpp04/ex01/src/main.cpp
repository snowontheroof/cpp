#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int	main(void)
{
	{
		std::cout << "---------Test 1---------" << std::endl;
		Animal* array[20];
		for (int i = 0; i < 20; i++)
		{
			if (i < 10)
				array[i] = new Cat();
			else
				array[i] = new Dog();
		}
		for (int i = 0; i < 20; i++)
		{
			std::cout << std::endl << array[i]->getType() << std::endl;
			array[i]->makeSound();
		}
		std::cout << std::endl;
		for (int i = 0; i < 20; i++)
			delete array[i];
	}

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
		std::cout << std::endl << puppy.getBrain()->getIdea(99) << std::endl << std::endl;
		puppy.getBrain()->setIdea(-15, "Is this a good idea?");
		std::cout << std::endl << puppy.getBrain()->getIdea(400) << std::endl;
	}

	return 0;
}
