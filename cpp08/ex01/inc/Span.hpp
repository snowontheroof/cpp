#pragma once
# include <algorithm>
# include <vector>
# include <iostream>
# include <exception>

class Span
{
	private:
		unsigned int			size;
		std::vector<int>		storage;

	public:
		Span() = delete;
		Span(unsigned int n);
		Span(const Span& obj);
		Span&					operator=(const Span& other);
		~Span();

		unsigned int			getSize() const;
		void					addNumber(int nb);
		int						shortestSpan() const;
		int						longestSpan() const;

		template <typename Iterator>
		void					addRange(Iterator begin, Iterator end)
		{
			auto	dist = std::distance(begin, end);
			if (dist <= 0)
				throw InvalidRangeException();
			if (dist + storage.size() > size)
				throw FullStorageException();
			storage.insert(storage.end(), begin, end);
		}

		class InvalidRangeException : public std::exception
		{
			const char*			what() const noexcept override;
		};

		class FullStorageException : public std::exception
		{
			const char*			what() const noexcept override;
		};

		class NoSpanException : public std::exception
		{
			const char*			what() const noexcept override;
		};
};
