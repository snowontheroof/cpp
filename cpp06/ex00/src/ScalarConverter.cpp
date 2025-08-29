#include "ScalarConverter.hpp"
#include <exception>

void	handle_char(std::string input, enum t_type type)
{
	if (type == INVALID || type == PSEUDO)
		std::cout << "impossible\n";
	else if (type == CHAR)
		std::cout << input[0] << std::endl;
	else
	{
		int	value;
		try
		{
			if (type == INT)
				value = std::stoi(input);
			else if (type == FLOAT)
				value = static_cast<int>(std::stof(input));
			else
				value = static_cast<int>(std::stod(input));
		}
		catch (std::out_of_range& e)
		{
			std::cout << "impossible\n";
			return;
		}
		if (value > 127)
			std::cout << "impossible\n";
		else if (value <= 126 && value >= 32)
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "Non displayable\n";
	}
}

void	handle_int(std::string input, enum t_type type)
{
	if (type == INVALID || type == PSEUDO)
		std::cout << "impossible\n";
	else if (type == CHAR)
		std::cout << static_cast<int>(input[0]) << std::endl;
	else
	{
		int	value;
		try
		{
			value = std::stoi(input);
			std::cout << value << std::endl;
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "impossible\n";
		}
	}
}

void	handle_float(std::string input, enum t_type type)
{
	if (type == INVALID)
		std::cout << "impossible\n";
	else if (type == CHAR)
		std::cout << static_cast<float>(input[0]) << ".0f\n";
	else if (type == PSEUDO)
	{
		if (input == "nanf" || input == "+inff" || input == "-inff")
			std::cout << input << std::endl;
		else
			std::cout << input << "f\n";
	}
	else
	{
		try
		{
			if (type == INT)
				std::cout << static_cast<float>(std::stoi(input)) << ".0f\n";
			else if (type == FLOAT)
				std::cout << static_cast<float>(std::stof(input)) << "f\n";
			else if (type == DOUBLE)
				std::cout << static_cast<float>(std::stod(input)) << std::endl;	
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "impossible\n";
		}
	}
}

void	handle_double(std::string input, enum t_type type)
{
	if (type == INVALID)
		std::cout << "impossible\n";
	else if (type == CHAR)
		std::cout << static_cast<double>(input[0]) << ".0\n";
	else if (type == PSEUDO)
	{
		if (input == "nan" || input == "+inf" || input == "-inf")
			std::cout << input << std::endl;
		else
			std::cout << input.substr(0, input.length() - 1) << std::endl;
	}
	else
	{
		try
		{
			if (type == INT)
				std::cout << static_cast<double>(std::stoi(input)) << ".0\n";
			else if (type == FLOAT)
				std::cout << static_cast<double>(std::stof(input)) << std::endl;
			else if (type == DOUBLE)
				std::cout << std::stof(input) << std::endl;	
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "impossible\n";
		}
	}
}

enum t_type	detect_decimal(std::string input)
{
	for (int i = 0; input[i]; i++)
	{
		if (input[i] == '.' && i != 0 && input[i + 1])
		{
			int dec = 0;
			i++;
			while (input[i] <= '9' && input[i] >= '0')
			{
				dec++;
				i++;
			}
			if (input[i] == 'f' && input[i - 1] != '.' && dec <= 7)
				return FLOAT;
			else if (!input[i] && dec <= 15)
				return DOUBLE;
			else
				return INVALID;
		}
	}
	return INVALID;
}

enum t_type	detect_type(std::string input)
{
	if (input.length() == 1)
		return CHAR;
	else if (input == "nan" || input == "+inf" || input == "-inf" ||input == "nanf" || input == "+inff" || input == "-inff")
		return PSEUDO;
	else if (input.length() > 1)
	{
		for (int i = 1; input[i]; i++)
		{
			if (!((input[i] <= '9' && input[i] >= '0') || input[i] == '.' || (input[i] == 'f' && !input[i + 1])))
				return INVALID;
			else if (input[i] == '.' && i != 0)
				return detect_decimal(input);
			else if (input[i] == '.')
				return INVALID;
		}
	}
	return INT;
}

void	ScalarConverter::convert(std::string input)
{
	enum t_type type = detect_type(input);
	std::cout << "char: ";
	handle_char(input, type);
	std::cout << "int: ";
	handle_int(input, type);
	std::cout << "float: ";
	handle_float(input, type);
	std::cout << "double: ";
	handle_double(input, type);
}