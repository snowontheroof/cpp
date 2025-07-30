#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "[This is a default idea]";
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = obj._ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

void	Brain::setIdea(int index, const std::string& input)
{
	_ideas[index] = input;
}

const std::string&	Brain::getIdea(int index) const
{
	return _ideas[index];
}
