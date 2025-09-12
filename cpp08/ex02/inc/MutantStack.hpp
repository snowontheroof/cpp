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