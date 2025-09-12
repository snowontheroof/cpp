#pragma once
# include <cstdint>
# include <iostream>

class Example
{
	public:
		std::string	name;
		int			value;
};

template <typename T, typename F>
void iter(T* array, int length, F funct)
{
	for (int i = 0; i < length; i++)
	{
		funct(array[i]);
	}
}
