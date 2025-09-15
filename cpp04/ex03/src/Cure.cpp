#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure: Constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure& obj) : AMateria(obj)
{
	std::cout << "Cure: Copy constructor called" << std::endl;
}

Cure&	Cure::operator=(const Cure& other)
{
	std::cout << "Cure: Copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure: Destructor called" << std::endl;
}

AMateria*	Cure::clone() const
{
	AMateria*	tmp = new Cure();
	return tmp;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
