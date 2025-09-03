#include "ScalarConverter.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void	testChar(void)
{
	std::cout << RED << "\nChar input\n\n" << RESET;

	std::cout << GREEN << "Test input: 'z'\n" << RESET;
	ScalarConverter::convert("z");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: 'A'\n" << RESET;
	ScalarConverter::convert("A");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '0'\n" << RESET;
	ScalarConverter::convert("0");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '&'\n" << RESET;
	ScalarConverter::convert("&");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '#'\n" << RESET;
	ScalarConverter::convert("#");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '}'\n" << RESET;
	ScalarConverter::convert("}");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '/'\n" << RESET;
	ScalarConverter::convert("/");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '!'\n" << RESET;
	ScalarConverter::convert("!");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '`'\n" << RESET;
	ScalarConverter::convert("`");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: ' ' (space)\n" << RESET;
	ScalarConverter::convert(" ");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '	' (tab)\n" << RESET;
	ScalarConverter::convert("	");
	std::cout << std::string(50, '-') << std::endl << std::endl;
}

void	testInt(void)
{
	std::cout << RED << "Int input\n\n" << RESET;

	std::cout << GREEN << "Test input: '42'\n" << RESET;
	ScalarConverter::convert("42");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '0'\n" << RESET;
	ScalarConverter::convert("0");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '987654'\n" << RESET;
	ScalarConverter::convert("987654");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-99'\n" << RESET;
	ScalarConverter::convert("-99");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-1'\n" << RESET;
	ScalarConverter::convert("-1");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '+55'\n" << RESET;
	ScalarConverter::convert("+55");
	std::cout << std::string(50, '-') << std::endl;

	int intMax = std::numeric_limits<int>::max();
	std::string intMax_str = std::to_string(intMax);
	std::cout << GREEN << "Test input: '" << intMax << "', INT_MAX\n" << RESET;
	ScalarConverter::convert(intMax_str);
	std::cout << std::string(50, '-') << std::endl;

	int intMin = std::numeric_limits<int>::min();
	std::string intMin_str = std::to_string(intMin);
	std::cout << GREEN << "Test input: '" << intMin << "', INT_MIN\n" << RESET;
	ScalarConverter::convert(intMin_str);
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '2147483648' (INT_MAX + 1)\n" << RESET;
	ScalarConverter::convert("2147483648");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-2147483649' (INT_MIN - 1)\n" << RESET;
	ScalarConverter::convert("-2147483649");
	std::cout << std::string(50, '-') << std::endl << std::endl;
}

void	testFloat(void)
{
	std::cout << RED << "Float input\n\n" << RESET;

	std::cout << GREEN << "Test input: '42.0f'\n" << RESET;
	ScalarConverter::convert("42.0f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '0.0f'\n" << RESET;
	ScalarConverter::convert("0.0f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '8.99f'\n" << RESET;
	ScalarConverter::convert("8.99f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-92.5f'\n" << RESET;
	ScalarConverter::convert("-92.5f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '5f'\n" << RESET;
	ScalarConverter::convert("5f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '+123.45f'\n" << RESET;
	ScalarConverter::convert("+123.45f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '42.f' (no decimal digits)\n" << RESET;
	ScalarConverter::convert("42.f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '.42f' (no integer part)\n" << RESET;
	ScalarConverter::convert(".42f");
	std::cout << std::string(50, '-') << std::endl;

	float floatMax = std::numeric_limits<float>::max();
	std::string floatMax_str = std::to_string(floatMax);
	std::cout << GREEN << "Test input: '" << floatMax_str << "', FLOAT_MAX\n" << RESET;
	ScalarConverter::convert(floatMax_str);
	std::cout << std::string(50, '-') << std::endl;

	float floatMin = std::numeric_limits<float>::lowest();
	std::string floatMin_str = std::to_string(floatMin);
	std::cout << GREEN << "Test input: '" << floatMin_str << "', FLOAT_LOWEST\n" << RESET;
	ScalarConverter::convert(floatMin_str);
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '3402823466385288598117041834845169254400.0f'" << "', FLOAT_MAX * 10\n" << RESET;
	ScalarConverter::convert("3402823466385288598117041834845169254400.0f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-3402823466385288598117041834845169254400.0f'" << "', FLOAT_LOWEST * 10\n" << RESET;
	ScalarConverter::convert("-3402823466385288598117041834845169254400.0f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-inff'\n" << RESET;
	ScalarConverter::convert("-inff");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '+inff'\n" << RESET;
	ScalarConverter::convert("+inff");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: 'nanf'\n" << RESET;
	ScalarConverter::convert("nanf");
	std::cout << std::string(50, '-') << std::endl << std::endl;
}

void	testDouble(void)
{
	std::cout << RED << "Double input\n\n" << RESET;

	std::cout << GREEN << "Test input: '42.0'\n" << RESET;
	ScalarConverter::convert("42.0");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '0.0'\n" << RESET;
	ScalarConverter::convert("0.0");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '8.9942'\n" << RESET;
	ScalarConverter::convert("8.9942");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-42.5'\n" << RESET;
	ScalarConverter::convert("-42.5");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-0.1'\n" << RESET;
	ScalarConverter::convert("-0.1");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '+1234.56789'\n" << RESET;
	ScalarConverter::convert("+1234.56789");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '42.' (no decimal digits)\n" << RESET;
	ScalarConverter::convert("42.");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '.42' (no integer part)\n" << RESET;
	ScalarConverter::convert(".42");
	std::cout << std::string(50, '-') << std::endl;

	double doubleMax = std::numeric_limits<double>::max();
	std::string doubleMax_str = std::to_string(doubleMax);
	std::cout << GREEN << "Test input: '" << doubleMax_str << "', DOUBLE_MAX\n" << RESET;
	ScalarConverter::convert(doubleMax_str);
	std::cout << std::string(50, '-') << std::endl;

	double doubleMin = std::numeric_limits<double>::lowest();
	std::string doubleMin_str = std::to_string(doubleMin);
	std::cout << GREEN << "Test input: '" << doubleMin_str << "', DOUBLE_LOWEST\n" << RESET;
	ScalarConverter::convert(doubleMin_str);
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0'" << "', DOUBLE_MAX * 10\n" << RESET;
	ScalarConverter::convert("1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0'" << "', DOUBLE_LOWEST * 10\n" << RESET;
	ScalarConverter::convert("-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-inf'\n" << RESET;
	ScalarConverter::convert("-inf");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '+inf'\n" << RESET;
	ScalarConverter::convert("+inf");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: 'nan'\n" << RESET;
	ScalarConverter::convert("nan");
	std::cout << std::string(50, '-') << std::endl << std::endl;
}

void	testInvalid(void)
{
	std::cout << RED << "Invalid input\n\n" << RESET;

	std::cout << GREEN << "Test input: 'lol'\n" << RESET;
	ScalarConverter::convert("lol");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '-+42'\n" << RESET;
	ScalarConverter::convert("-+42");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '++42'\n" << RESET;
	ScalarConverter::convert("++42");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '--4242'\n" << RESET;
	ScalarConverter::convert("--4242");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '42lol'\n" << RESET;
	ScalarConverter::convert("42lol");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: 'lol.42'\n" << RESET;
	ScalarConverter::convert("lol.42");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '42.0.0f'\n" << RESET;
	ScalarConverter::convert("42.0.0f");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '42ff'\n" << RESET;
	ScalarConverter::convert("42ff");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: 'f42'\n" << RESET;
	ScalarConverter::convert("f42");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '1.23f€'\n" << RESET;
	ScalarConverter::convert("1.23f€");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '42.0.9'\n" << RESET;
	ScalarConverter::convert("42.0.9");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '42..0'\n" << RESET;
	ScalarConverter::convert("42..0");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '' (empty string)\n" << RESET;
	ScalarConverter::convert("");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '   ' (spaces)\n" << RESET;
	ScalarConverter::convert("   ");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '❤' (unicode)\n" << RESET;
	ScalarConverter::convert("❤");
	std::cout << std::string(50, '-') << std::endl;

	std::cout << GREEN << "Test input: '€'\n" << RESET;
	ScalarConverter::convert("€");
	std::cout << std::string(50, '-') << std::endl << std::endl;
}

void	tests(void)
{
	testChar();
	testInt();
	testFloat();
	testDouble();
	testInvalid();
}
