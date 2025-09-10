#pragma once

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& obj);
		MutantStack&	operator=(const MutantStack& other) = delete;
		~MutantStack();
};