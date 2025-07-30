#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Ice: Default constructor called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice& obj) : AMateria(obj)
{
	std::cout << "Ice: Copy constructor called" << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	std::cout << "Ice: Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice: Destructor called" << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria*	tmp = new Ice();
	return tmp;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
