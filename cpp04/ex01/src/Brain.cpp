#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "[This is a default idea]";
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
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

void	Brain::setIdea(int idx, const std::string& input)
{
	if (idx < 0 || idx > 99)
		std::cout << "Error: index " << idx << " is out of bounds!" << std::endl;
	else
		_ideas[idx] = input;
}

std::string	Brain::getIdea(int idx) const
{
	if (idx < 0 || idx > 99)
	{
		std::cout << "Error: index " << idx << " is out of bounds!" << std::endl;
		return "";
	}
	return _ideas[idx];
}
