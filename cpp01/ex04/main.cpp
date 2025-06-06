/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:34:39 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 13:51:40 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::string	newFileName = filename + ".replace";
	std::ofstream	newFile(newFileName);
	if (!newFile)
	{
		std::cerr << "Error: could not create .replace file" << std::endl;
		return ;
	}
	std::string	line;
	std::size_t	found;

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
}

int main(void)
{
	replacer("testfile", "testing", "_TRYING_");
	replacer("anothertest", "", "HELLOO");
	replacer("thirdtest", "s", "j");
	replacer("fourthtest", "11", "");
	return 0;
}
