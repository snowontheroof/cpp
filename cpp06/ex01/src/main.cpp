#include "Serializer.hpp"

int	main(void)
{
	Serializer	test;
	Data*		jihuu = new Data();
	uintptr_t	res = test.serialize(jihuu);
	std::cout << res << std::endl;
	std::cout << test.deserialize(res) << std::endl;

	delete jihuu;
	return 0;
}
