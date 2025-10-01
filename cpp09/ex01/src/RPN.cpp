#include "../inc/RPN.hpp"

void	RPN::runOperation(long long a, long long b, char o)
{
	long long	res = 0;
	switch (o)
	{
		case '+':
			res = a + b;
			break;
		case '-':
			res = a - b;
			break;
		case '*':
			res = a * b;
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error(DIVERR);
			res = a / b;
			break;
		default:
			break;
	}
	if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
		throw std::out_of_range(RESERR);
	_stack.push(static_cast<int>(res));
}

static bool	isOperator(char c, bool sign)
{
	if (sign)
		return (c == '+' || c == '-');
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

static bool	isValidToken(std::string token)
{
	if (token.size() == 1 && ((isOperator(token[0], 0)) || std::isdigit(token[0])))
		return true;
	if (token.size() == 2 && isOperator(token[0], 1) && std::isdigit(token[1]))
		return true;
	return false;
}

RPN::RPN(std::string input)
{
	std::stringstream	ss(input);
	std::string			token;
	while (ss >> token)
	{
		if (!isValidToken(token))
			throw std::runtime_error("");
		if (token.size() == 1 && isOperator(token[0], 0))
		{
			if (_stack.size() < 2)
				throw std::runtime_error(ARGERR);
			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			runOperation(static_cast<long long>(a), static_cast<long long>(b), token[0]);
		}
		else
		{
			int	nb = std::stoi(token);
			_stack.push(nb);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error(ARGERR);
	else
		std::cout << _stack.top() << std::endl;
}
