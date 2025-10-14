#include "../inc/BitcoinExhange.hpp"

std::map<std::string, float>	BitcoinExhange::dataBase;

void	BitcoinExhange::loadDataBase(std::ifstream& file)
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

static bool	isValidDate(std::string& date)
{
	if (!std::regex_match(date,
			std::regex("(19|20)\\d{2}-(0[1-9]|1[012])-(0[1-9]|[12][0-9]|3[01])")))
		return false;

	int					year;
	unsigned int		month, day;
	char				separator;
	std::stringstream	stream(date);

	if (!(stream >> year >> separator >> month >> separator >> day))
		return false;
	std::chrono::year_month_day	ymd = { std::chrono::year{year},
		std::chrono::month{month}, std::chrono::day{day} };
	if (!ymd.ok())
		return false;
	return true;
}

static bool	isValidValue(std::string& line, std::string& valueStr, float& value)
{
	if (valueStr.empty())
	{
		std::cout << "Error: bad input => " << line << '\n';
		return false;
	}
	unsigned int	dots = 0;
	for (size_t i = 0; valueStr[i]; i++)
	{
		if (!((i == 0 && (valueStr[i] == '-' || valueStr[i] == '+'))
			|| std::isdigit(valueStr[i]) || (valueStr[i] == '.' && !dots)))
		{
			std::cout << "Error: bad input => " << valueStr << '\n';
			return false;
		}
		else if (valueStr[i] == '.')
			dots++;
	}
	try
	{
		value = std::stof(valueStr);
		if (value < 0)
		{
			std::cout << "Error: not a positive number.\n";
			return false;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number.\n";
			return false;
		}
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "Error: not a valid value.\n";
		return false;
	}
	return true;
}

void	BitcoinExhange::handleInput(std::ifstream& file)
{
	std::string	line;
	float		value;

	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid input file structure");
	while (std::getline(file, line))
	{
		size_t	pos = line.find('|');
		std::string	date = line.substr(0, pos - 1);
		if (pos == std::string::npos || !isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << '\n';
			continue ;
		}
		std::string	valueStr = line.substr(pos + 2);
		if (!isValidValue(line, valueStr, value))
			continue ;
		std::map<std::string, float>::iterator	it = dataBase.lower_bound(date);
		float	closestValue = it->second;
		if (it->first != date)
		{
			if (it == dataBase.begin())
			{
				std::cout
				<< "Error: given date is before the earliest date available in database.\n";
				continue ;
			}
			it--;
			closestValue = it->second;
		}
		std::cout << date << " => " << value << " = "
			<< closestValue * value << std::endl;
	}
}

void	BitcoinExhange::btc(std::string& inputFile)
{
	std::ifstream	dataFile("data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Error: failed to open database");
	loadDataBase(dataFile);
	std::ifstream	file(inputFile);
	if (!file.is_open())
		throw std::runtime_error("Error: failed to open file");
	handleInput(file);
}
