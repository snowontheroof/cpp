#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	A_Animal* array[30];
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
	for (int i = 0; i < 30; i++)
		delete array[i];

	Dog	puppy;

	std::cout << std::endl << puppy.getIdea(3) << std::endl;

	return 0;
}
