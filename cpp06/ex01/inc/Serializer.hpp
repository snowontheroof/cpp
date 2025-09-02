#pragma once
# include <iostream>
# include <cstdint>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer() = delete;
		Serializer(const Serializer& obj) = delete;
		Serializer&	operator=(const Serializer& other) = delete;
		~Serializer() = delete;

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
