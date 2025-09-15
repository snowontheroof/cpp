#include <iostream>
#include <string>
#include <fstream>

void	replacer(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	myFile(filename);
	if (!myFile)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	std::string		newFileName = filename + ".replace";
	std::ofstream	newFile(newFileName);
	if (!newFile)
	{
		std::cerr << "Error: could not create .replace file" << std::endl;
		return ;
	}
	std::string		line;
	std::size_t		found;

	while (std::getline(myFile, line))
	{
		if (s1 != "")
		{
			found = line.find(s1);
			while (found != std::string::npos)
			{
				line.erase(found, s1.length());
				line.insert(found, s2);
				found = line.find(s1);
			}
		}
		newFile << line << std::endl;
	}
	myFile.close();
	newFile.close();
}

int main(void)
{
	try
	{
		replacer("testfile", "testing", "_TRYING_");
		replacer("anothertest", "", "HELLOO");
		replacer("thirdtest", "s", "j");
		replacer("fourthtest", "11", "");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

/*int main(int argc, char **argv)
{
	if (argc == 4)
	{
		try
		{
			replacer(argv[1], argv[2], argv[3]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Expected usage: ./Replacer <filename> <s1> <s2>" << std::endl;
	return 0;
}*/
