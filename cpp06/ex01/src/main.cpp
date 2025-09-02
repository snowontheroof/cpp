#include "Serializer.hpp"

int	main(void)
{
	Data	test;

	uintptr_t	raw = Serializer::serialize(&test);
	std::cout << &test << std::endl;
	std::cout << "0x" << std::hex << raw << std::endl;

	Data*	ptr = Serializer::deserialize(raw);
	std::cout << ptr << std::endl;

	return 0;
}
