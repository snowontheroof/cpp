#pragma once
# include <iostream>
# include <map>
# include <fstream>
# include <exception>

class BitcoinExhange
{
	private:
		std::map<std::string, float>	dataBase;
		std::map<std::string, float>	inputData;

	public:
		BitcoinExhange();
		BitcoinExhange(const BitcoinExhange& obj) = delete;
		BitcoinExhange&		operator=(const BitcoinExhange& other);
		~BitcoinExhange();

		void	btc(std::string input);
		void	handleDataBase(std::ifstream& file);
		void	handleInput(std::ifstream& file);
};
