#pragma once
# include <stack>
# include <iostream>
# include <sstream>
# include <limits>
# define ARGERR ": numeric arguments and operators not in balance"
# define DIVERR ": division by zero"
# define RESERR ": calculation result is outside of int limits"

class RPN
{
	private:
		std::stack<int>	_stack;

		void			runOperation(long long a, long long b, char o);

	public:
		RPN() = delete;
		RPN(std::string input);
		RPN(const RPN& obj) = delete;
		RPN&			operator=(const RPN& other) = delete;
		~RPN() = default;
};
