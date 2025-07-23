#include "../inc/Dog.hpp"

Dog::Dog() : A_Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
	ideas = new Brain();
}

Dog::Dog(const Dog& obj) : A_Animal(obj)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	A_Animal::operator=(other);
	if (this != &other)
		type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

void	Dog::setIdea(int index, std::string input)
{
	ideas->ideas[index] = input;
}

std::string&	Dog::getIdea(int index) const
{
	return (ideas->ideas[index]);
}

void	Dog::makeSound() const
{
	std::cout << "Woof, woof!! Bark!" << std::endl;
}
