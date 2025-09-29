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

class BitcoinExhange
{
	private:
		std::map<std::string, float>	dataBase;

	public:
		BitcoinExhange();
		BitcoinExhange(const BitcoinExhange& obj) = delete;
		BitcoinExhange&		operator=(const BitcoinExhange& other);
		~BitcoinExhange();

		void	btc(std::string& inputFile);
		void	handleDataBase(std::ifstream& file);
		void	handleInput(std::ifstream& file);
		void	displayExhange(void);
};
