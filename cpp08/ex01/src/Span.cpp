#include "../inc/Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : size(n)
{
	storage.reserve(n);
}

Span::Span(const Span& obj) : size(obj.size)
{
	storage.reserve(size);
	storage = obj.storage;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		storage = other.storage;
		size = other.size;
	}
	return *this;
}

Span::~Span()
{
}

const std::vector<int>&	Span::getStorage() const
{
	return storage;
}

unsigned int	Span::getSize() const
{
	return size;
}

void	Span::addNumber(int nb)
{
	if (storage.size() >= size)
		throw FullStorageException();
	storage.push_back(nb);
}

int	Span::longestSpan() const
{
	if (storage.size() <= 1)
		throw NoSpanException();
	int	span = *std::max_element(storage.begin(), storage.end())
		- *std::min_element(storage.begin(), storage.end());
	return span;
}

int	Span::shortestSpan() const
{
	if (storage.size() <= 1)
		throw NoSpanException();
	int	span = abs(storage[0] - storage[1]);
	for (size_t i = 0; i < storage.size(); i++)
	{
		for (size_t	j = 1; j < storage.size(); j++)
		{
			if (j != i && abs(storage[i] - storage[j]) < span)
				span = abs(storage[i] - storage[j]);
		}
	}
	return span;
}

const char*	Span::FullStorageException::what() const noexcept
{
	return "Not enough room to add number!";
}

const char*	Span::NoSpanException::what() const noexcept
{
	return "Not enough elements to have a span!";
}
