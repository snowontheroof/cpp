#include "../inc/Data.hpp"

Data::Data() : _name("Default"), _value(0)
{
}

Data::Data(std::string name, int value) : _name(name), _value(value)
{
}

Data::Data(const Data& obj) : _name(obj._name), _value(obj._value)
{
}

Data&	Data::operator=(const Data& other)
{
	if (this != &other)
	{
		_name = other._name;
		_value = other._value;
	}
	return *this;
}

Data::~Data()
{
}

void	Data::setName(std::string name)
{
	_name = name;
}

void	Data::setValue(int value)
{
	_value = value;
}

const std::string&	Data::getName() const
{
	return _name;
}

int	Data::getValue() const
{
	return _value;
}
