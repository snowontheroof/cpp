#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal* array[30];
	for (int i = 0; i < 30; i++)
	{
		if (i % 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	for (int i = 0; i < 30; i++)
	{
		std::cout << std::endl << array[i]->getType() << std::endl;
		array[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < 30; i++)
		delete array[i];

	std::cout << std::endl;
	const Dog	puppy;

	std::cout << std::endl << puppy.getBrain()->getIdea(3) << std::endl;
	puppy.getBrain()->setIdea(3, "Should we get some bones??");
	std::cout << std::endl << puppy.getBrain()->getIdea(3) << std::endl;
	std::cout << std::endl << puppy.getBrain()->getIdea(99) << std::endl << std::endl;

	return 0;
}
