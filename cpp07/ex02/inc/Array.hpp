#pragma once
# include <iostream>

template <typename T> class Array
{
	public:
		T*				_array;
		unsigned int	_elems;

		Array();
		Array(unsigned int n);
		Array(const Array& obj);
		Array&	operator=(const Array& other) = delete;
		~Array();

		unsigned int	size();
};

template <typename T>
Array<T>::Array()
{
	_array = nullptr;
	_elems = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_elems = n;
	_array = new T[n]{};

	for (unsigned int i = 0; i < n; i++)
		std::cout << _array[i] << std::endl;
}

template <typename T>
Array<T>::Array(const Array& obj) : _elems(obj._elems)
{
	unsigned int	n = obj.size();
	_array = new T[n]{};
	for (unsigned int i = 0; i < n; i++)
		_array[i] = obj._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
unsigned int	Array<T>::size()
{
	return _elems;
}

//WE NEED OVERLOAD OPERATOR FOR []
