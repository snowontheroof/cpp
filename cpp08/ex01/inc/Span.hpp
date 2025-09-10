#pragma once
# include <vector>
# include <iostream>
# include <exception>

class Span
{
	private:
		std::vector<int>	storage;
		unsigned int		size;
	
	public:
		Span() = delete;
		Span(unsigned int n);
		Span(const Span& obj);
		Span&	operator=(const Span& other);
		~Span();

		std::vector<int>	getStorage() const;
		void				addNumber(int nb);
		void				addNumbers(std::vector<int> sequence);
		int					shortestSpan() const;
		int					longestSpan() const;

		class FullStorageException : public std::exception
		{
			const char*	what() const noexcept override;
		};

		class NoSpanException : public std::exception
		{
			const char*	what() const noexcept override;
		};
};