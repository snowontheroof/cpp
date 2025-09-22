#pragma once
# include <iostream>
# include <vector>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() = default;
		MutantStack(const MutantStack& obj) = default;
		MutantStack&	operator=(const MutantStack& other) = delete;
		~MutantStack() = default;

		using iterator = typename std::stack<T>::container_type::iterator;

		iterator	begin(void);
		iterator	end(void);
};

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return	this->c.end();
}
