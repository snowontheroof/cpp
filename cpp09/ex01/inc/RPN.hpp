#pragma once
# include <stack>
# include <iostream>
# include <sstream>

class RPN
{
	private:
		std::stack<std::string>	_stack;

	public:
		RPN() = delete;
		RPN(std::string input);
		RPN(const RPN& obj) = delete;
		RPN&	operator=(const RPN& other) = delete;
		~RPN();
};
