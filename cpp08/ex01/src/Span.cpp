#include "../inc/Span.hpp"

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
		size = other.size;
		storage = other.storage;
	}
	return *this;
}

Span::~Span()
{
}

unsigned int	Span::getSize() const
{
	return size;
}

void	Span::addNumber(int nb)
{
	if (storage.size() + 1 > size)
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
	std::vector<int>	tmp = storage;
	std::sort(tmp.begin(), tmp.end());
	int	span = abs(tmp[0] - tmp[1]);
	for (size_t i = 0; i + 1 < tmp.size(); i++)
	{
		if (abs(tmp[i] - tmp[i + 1]) < span)
			span = abs(tmp[i] - tmp[i + 1]);
	}
	return span;
}

const char*	Span::InvalidRangeException::what() const noexcept
{
	return "Invalid range to add!";
}

const char*	Span::FullStorageException::what() const noexcept
{
	return "Not enough room to add number(s)!";
}

const char*	Span::NoSpanException::what() const noexcept
{
	return "Not enough elements to have a span!";
}
