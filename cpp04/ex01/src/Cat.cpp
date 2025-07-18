#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	type = "Cat";
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	Animal::operator=(other);
	if (this != &other)
		type = "Cat";
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!! Meouww!" << std::endl;
}
