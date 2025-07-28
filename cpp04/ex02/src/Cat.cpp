#include "../inc/Cat.hpp"

Cat::Cat() : A_Animal()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	type = "Cat";
	ideas = new Brain();
}

Cat::Cat(const Cat& obj) : A_Animal(obj)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	A_Animal::operator=(other);
	if (this != &other)
		type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return ideas;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!! Meouww!" << std::endl;
}
