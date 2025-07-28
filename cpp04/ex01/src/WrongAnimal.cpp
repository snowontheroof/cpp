#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : type(obj.type)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[ThIs Is NoT tHe RiGhT sTaNdArD aNiMaL sOuNd]" << std::endl;
}
