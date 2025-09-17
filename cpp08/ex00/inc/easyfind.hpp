#pragma once
# include <iostream>

template <typename T>
int	easyfind(T cont, int nb)
{
	typename T::const_iterator	it = find(nb);
	if (it != cont.end())
		return 1;
	return -1;
}
