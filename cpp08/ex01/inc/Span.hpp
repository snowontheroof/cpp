#pragma once
# include <vector>
# include <iostream>
# include <exception>

class Span
{
	private:
		std::vector<int>		storage;
		unsigned int			size;

	public:
		Span() = delete;
		Span(unsigned int n);
		Span(const Span& obj);
		Span&					operator=(const Span& other);
		~Span();

		const std::vector<int>&	getStorage() const;
		unsigned int			getSize() const;
		void					addNumber(int nb);
		template <typename Iterator>
		void					addRange(Iterator begin, Iterator end);
		int						shortestSpan() const;
		int						longestSpan() const;

		class FullStorageException : public std::exception
		{
			const char*			what() const noexcept override;
		};

		class NoSpanException : public std::exception
		{
			const char*			what() const noexcept override;
		};
};

template <typename Iterator>
void	Span::addRange(Iterator begin, Iterator end)
{
	unsigned long	dist = std::distance(begin, end);
	if (dist != 0)
	{
		if (size - storage.size() < dist)
			throw FullStorageException();
		storage.insert(storage.end(), begin, end);
	}
}
