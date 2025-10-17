#pragma once
# include <iostream>
# include <map>
# include <fstream>
# include <exception>
# include <iomanip>
# include <chrono>
# include <sstream>
# include <algorithm>
# include <regex>
# define INV_DB "invalid database"
# define INV_INPUT "invalid input file structure"
# define DBOPEN_ERR "failed to open database"
# define INPUTOPEN_ERR "failed to open input file"

class BitcoinExchange
{
	private:
		static std::map<std::string, float>	database;

		BitcoinExchange() = delete;
		BitcoinExchange(const BitcoinExchange& obj) = delete;
		BitcoinExchange&	operator=(const BitcoinExchange& other) = delete;
		~BitcoinExchange() = delete;

		static void		loadDatabase(std::ifstream& file);
		static void		handleInput(std::ifstream& file);

	public:
		static void		btc(std::string& inputFile);
};
