#pragma once
# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator	easyfind(T cont, int nb)
{
	typename T::iterator	it = std::find(cont.begin(), cont.end(), nb);
	if (it == cont.end())
		throw std::runtime_error("Value not found");
	return it;
}
