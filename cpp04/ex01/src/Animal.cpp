#include "Animal.hpp"

Animal::Animal() : type("Default")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.type)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}

void	Animal::makeSound() const
{
	std::cout << "[Standard animal sound]" << std::endl;
}
