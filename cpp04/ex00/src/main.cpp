#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	const WrongAnimal *weird = new WrongAnimal();
	const WrongAnimal *odd = new WrongCat;

	std::cout << std::endl;
	std::cout << weird->getType() << " " << std::endl;
	std::cout << odd->getType() << " " << std::endl;
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
