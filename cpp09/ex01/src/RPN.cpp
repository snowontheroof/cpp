#include "../inc/RPN.hpp"

void	runOperation(char o)
{
	if (o == '+')
}

RPN::RPN(std::string input)
{
	std::stringstream	ss(input);
	std::string			token;
	while (ss >> token)
	{
		std::cout << token << std::endl;
		if (token == "+" || token == "-" || token == "*" || token == "/")
			runOperation(token[0]);
		else
			_stack.push(token);
	}
	std::cout << "stack size is " << _stack.size() << std::endl;
}

RPN::~RPN()
{
}
