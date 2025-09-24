#include "../inc/BitcoinExhange.hpp"

BitcoinExhange::BitcoinExhange()
{
}

BitcoinExhange::~BitcoinExhange()
{
}

void	BitcoinExhange::handleDataBase(std::ifstream& file)
{
	std::string	line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	pos = line.find(',');
		std::string	date = line.substr(0, pos);
		std::string	value = line.substr(pos + 1);
		dataBase.insert({date, std::stof(value)});
	}
}

static bool	isValidDate(std::string date)
{
	std::stringstream	ss(date);
	std::string			word;
	bool				longMonth = true;
	bool				leapYear = false;
	int					month;

	size_t	pos = date.find('-');
	if (pos != std::string::npos)
		word = date.substr(0, pos);
	if (word.length() != 4)
		return false;
	try
	{
		int	year = std::stoi(word);
		if (year < 0 || year >= 2100)
			return false;
		if (year % 4 == 0 || year % 100 == 0 || year % 400 == 0)
			leapYear = true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
	date = date.substr(pos + 1);
	pos = date.find('-');
	word = date.substr(0, pos);
	if (word.length() != 2)
		return false;
	try
	{
		month = std::stoi(word);
		if (month < 1 || month > 12)
			return false;
		if (month == 6 || month == 9 || month == 11 || month == 4 || month == 2)
			longMonth = false;
	}
	catch(const std::exception& e)
	{
		return false;
	}
	date = date.substr(pos + 1);
	word = date;
	if (word.length() != 2)
		return false;
	try
	{
		int	day = std::stoi(word);
		if (day < 1 || (day > 31 && longMonth) || (day > 30 && !longMonth)
				|| (month == 2 && ((day > 28 && !leapYear) || (day > 29 && leapYear))))
			return false;
	}
	catch(const std::exception& e)
	{
		return false;
	}
	return true;
}

static bool	isValidValue(float value)
{
	if (value < 0)
	{
		std::cout << "Error: Not a positive integer.\n";
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: Too large a number.\n";
		return false;
	}
	return true;
}

void	BitcoinExhange::handleInput(std::ifstream& file)
{
	std::string	line;
	float		value;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	pos = line.find('|');
		std::string	date = line.substr(0, pos - 1);
		if (pos == std::string::npos || !isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << '\n';
			return ;
		}
		std::string	valueStr = line.substr(pos + 2);
		if (valueStr.empty())
		{
			std::cout << "Error: bad input => " << line << '\n';
			return ;
		}
		try
		{
			value = std::stof(valueStr);
			if (!isValidValue(value))
				return ;
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "Error: Not a valid value.\n";
		}
		float	closestValue = std::lower_bound(dataBase.begin()->second, dataBase.end()->second, value);
		std::cout << date << " => " << value << " = "
			<< dataBase.find(date)->second * value << std::endl;
	}
}

void	BitcoinExhange::btc(std::string& inputFile)
{
	std::ifstream	dataFile("data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Error: failed to open database");
	handleDataBase(dataFile);
	std::ifstream	file(inputFile);
	if (!file.is_open())
		throw std::runtime_error("Error: failed to open file");
	handleInput(file);
	// std::map<std::string, float>::iterator	it;
	// for (it = dataBase.begin(); it != dataBase.end(); it++)
	// 	std::cout << it->first << " " << it->second << std::endl;
}
