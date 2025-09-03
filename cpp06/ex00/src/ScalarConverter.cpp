#include "ScalarConverter.hpp"
#include <exception>
#include <iomanip>

int	find_decimals(std::string input)
{
	if (input.find('.') == std::string::npos)
		return 1;
	int	dec = 0;
	size_t	i = input.find('.') + 1;
	while (input[i] && std::isdigit(input[i]))
	{
		dec++;
		i++;
	}
	return dec;
}

void	handle_char(std::string input, enum e_type type)
{
	std::cout << "char: ";
	if (type == INVALID || type == PSEUDO)
		std::cout << "impossible\n";
	else if (type == CHAR)
	{
		char	c = static_cast<char>(input[0]);
		if (std::isprint(c))
			std::cout << "'" << c << "'\n";
		else
			std::cout << "Non displayable\n";
	}
	else
	{
		double	value;
		try
		{
			value = std::stod(input);
			if (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min())
				throw std::out_of_range("");
		}
		catch (std::out_of_range& e)
		{
			std::cout << "impossible\n";
			return;
		}
		if (std::isprint(value))
			std::cout << "'" << static_cast<char>(value) << "'\n";
		else
			std::cout << "Non displayable\n";
	}
}

void	handle_int(std::string input, enum e_type type)
{
	std::cout << "int: ";
	if (type == INVALID || type == PSEUDO)
		std::cout << "impossible\n";
	else if (type == CHAR)
		std::cout << static_cast<int>(input[0]) << "\n";
	else
	{
		try
		{
			double	value = std::stod(input);
			if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
				throw std::out_of_range("");
			int		res = static_cast<int>(value);
			std::cout << res << "\n";
		}
		catch(const std::invalid_argument& e)
		{
			std::cout << "impossible\n";
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "impossible\n";
		}
	}
}

void	handle_float(std::string input, enum e_type type, int decimals)
{
	std::cout << "float: ";
	if (type == INVALID)
		std::cout << "impossible\n";
	else if (type == CHAR)
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f\n";
	else if (type == PSEUDO)
	{
		if (input == "nanf" || input == "+inff" || input == "-inff")
			std::cout << input << "\n";
		else
			std::cout << input << "f\n";
	}
	else
	{
		try
		{
			double	value = std::stod(input);
			if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest())
				throw std::out_of_range("");
			float	res = static_cast<float>(value);
			std::cout << std::fixed << std::setprecision(decimals) << res << "f\n";
		}
		catch(const std::invalid_argument& e)
		{
			std::cout << "impossible\n";
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "impossible\n";
		}
	}
}

void	handle_double(std::string input, enum e_type type, int decimals)
{
	std::cout << "double: ";
	if (type == INVALID)
		std::cout << "impossible\n";
	else if (type == CHAR)
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << "\n";
	else if (type == PSEUDO)
	{
		if (input == "nan" || input == "+inf" || input == "-inf")
			std::cout << input << "\n";
		else
			std::cout << input.substr(0, input.length() - 1) << "\n";
	}
	else
	{
		try
		{
			double	value = std::stod(input);
			std::cout << std::fixed << std::setprecision(decimals) << value << "\n";
		}
		catch(const std::invalid_argument& e)
		{
			std::cout << "impossible\n";
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "impossible\n";
		}
	}
}

bool	is_int(std::string input, int dots)
{
	if (input.find('f') != std::string::npos || dots)
		return false;
	try
	{
		std::stoi(input);
	}
	catch(const std::out_of_range& e)
	{
		return false;
	}
	return true;
}

bool	is_float(std::string input)
{
	if (input.find('f') == std::string::npos)
		return false;
	try
	{
		std::stof(input);
	}
	catch(const std::out_of_range& e)
	{
		return false;
	}
	return true;
}

bool	is_double(std::string input)
{
	try
	{
		std::stod(input);
	}
	catch(const std::out_of_range& e)
	{
		return false;
	}
	return true;
}

enum e_type	detect_nb(std::string input)
{
	int		dots = 0;
	size_t	i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;
	if (!std::isdigit(input[i]))
		return INVALID;
	while (input[i])
	{
		if (!(std::isdigit(input[i])
				|| (input[i] == '.' && input[i + 1] && input[i + 1] != 'f')
				|| (input[i] == 'f' && !input[i + 1])))
			return INVALID;
		if (input[i] == '.')
			dots++;
		if (dots > 1)
			return INVALID;
		i++;
	}
	if (is_int(input, dots))
		return INT;
	if (is_float(input))
		return FLOAT;
	if (is_double(input))
		return DOUBLE;
	return INVALID;
}

enum e_type	detect_type(std::string input)
{
	if (input.length() == 1 && !(std::isdigit(input[0])))
		return CHAR;
	else if (input == "nan" || input == "+inf" || input == "-inf"
			|| input == "nanf" || input == "+inff" || input == "-inff")
		return PSEUDO;
	else
		return detect_nb(input);
}

void	ScalarConverter::convert(std::string input)
{
	enum e_type	type = detect_type(input);
	int 		decimals = find_decimals(input);

	handle_char(input, type);
	handle_int(input, type);
	handle_float(input, type, decimals);
	handle_double(input, type, decimals);
}
