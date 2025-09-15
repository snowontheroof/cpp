#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria: Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj) : _type(obj._type)
{
	std::cout << "AMateria: Copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria: Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria: Destructor called" << std::endl;
}

const std::string&	AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "An abstract materia used on " << target.getName() << std::endl;
}
