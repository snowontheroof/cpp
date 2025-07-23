#include "A_Animal.hpp"

A_Animal::A_Animal() : type("Default")
{
	std::cout << "A_Animal: Default constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal& obj) : type(obj.type)
{
	std::cout << "A_Animal: Copy constructor called" << std::endl;
}

A_Animal&	A_Animal::operator=(const A_Animal& other)
{
	std::cout << "A_Animal: Copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

A_Animal::~A_Animal()
{
	std::cout << "A_Animal: Destructor called" << std::endl;
}

std::string	A_Animal::getType() const
{
	return (type);
}
