#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
	ideas = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	Animal::operator=(other);
	if (this != &other)
		type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return ideas;
}

void	Dog::makeSound() const
{
	std::cout << "Woof, woof!! Bark!" << std::endl;
}
