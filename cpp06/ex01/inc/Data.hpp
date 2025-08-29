#pragma once
# include <iostream>

class Data
{
	private:
		int	value;

	public:
		Data();
		Data(const Data& obj);
		Data&	operator=(const Data& other);
		~Data();
};