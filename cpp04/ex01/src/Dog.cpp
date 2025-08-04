#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	_type = "Dog";
	_myBrain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	_myBrain = new Brain(*obj._myBrain);
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _myBrain;
		_myBrain = new Brain(*other._myBrain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete _myBrain;
}

Brain*	Dog::getBrain() const
{
	return _myBrain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof, woof!! Bark!" << std::endl;
}
