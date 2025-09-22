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

void	BitcoinExhange::handleInput(std::ifstream& file)
{
	std::string	line;

	std::getline(file, line);
	if (line == "data | value")
		;
	while (std::getline(file, line))
	{
		size_t	pos = line.find('|');
		std::string	date = line.substr(0, pos - 1);
		std::string	value = line.substr(pos + 2);
		inputData.insert({date, std::stof(value)});
	}
}

void	BitcoinExhange::btc(std::string inputFile)
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
