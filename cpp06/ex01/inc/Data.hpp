#pragma once
# include <iostream>

class Data
{
	private:
		std::string	_name;
		int			_value;

	public:
		Data();
		Data(std::string name, int value);
		Data(const Data& obj);
		Data&	operator=(const Data& other);
		~Data();

		void				setName(std::string name);
		void				setValue(int value);
		const std::string&	getName() const;
		int					getValue() const;
};
