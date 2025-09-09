#pragma once
# include <iostream>

template <typename T>
int	easyfind(T cont, int nb)
{
	typename T::const_iterator	it = std::find(cont.begin(), cont.end(), nb);
	if (it != cont.end())
		return 1;
	return -1;
}