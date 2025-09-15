#include "PhoneBook.hpp"
#include "Contact.hpp"

int	addContactInfo(std::string msg, std::string& field)
{
	std::cout << msg;
	std::getline(std::cin, field);
	if (std::cin.eof())
	{
		std::cout << std::endl << "Exiting phonebook" << std::endl;
		exit(0);
	}
	if (field == "")
	{
		std::cerr << "You must type something to each field!" << std::endl;
		std::cout << msg;
		std::getline(std::cin, field);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exiting phonebook" << std::endl;
			exit(0);
		}
		if (field == "")
		{
			std::cerr << "You must type something to each field!" << std::endl;
			std::cout << "Returning to main menu" << std::endl;
			std::cout << "----------------------------" << std::endl;
			return (-1);
		}
	}
	return (0);
}

void	addContact(PhoneBook& MyPhoneBook, int& i)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	if (i == 8)
		i = 0;
	std::cout << "Let's add a new contact! Please give me some info:" << std::endl;
	if (addContactInfo("First name: ", first_name) < 0)
		return ;
	if (addContactInfo("Last name: ", last_name) < 0)
		return ;
	if (addContactInfo("Nickname: ", nickname) < 0)
		return ;
	if (addContactInfo("Phone number: ", phone_number) < 0)
		return ;
	if (addContactInfo("Darkest secret: ", darkest_secret) < 0)
		return ;
	std::cout << "Contact added!" << std::endl;
	std::cout << "----------------------------" << std::endl;
	MyPhoneBook.setContact(MyPhoneBook, i, first_name, last_name, nickname,
		phone_number, darkest_secret);
	i++;
}

int	main(int argc, char **)
{
	std::string	buf;
	PhoneBook	MyPhoneBook;
	int			i = 0;

	if (argc != 1)
		std::cerr << "No arguments accepted at this point!" << std::endl;
	else
	{
		while (1)
		{
			std::cout << "What should we do?" << std::endl << "ADD: save a new contact"
				<< std::endl << "SEARCH: display a specific contact" << std::endl
				<< "EXIT: exit phonebook" << std::endl;
			std::getline(std::cin, buf);
			if (std::cin.eof())
			{
				std::cout << "Exiting phonebook" << std::endl;
				break ;
			}
			if (buf == "ADD")
				addContact(MyPhoneBook, i);
			else if (buf == "SEARCH")
				MyPhoneBook.searchContact(MyPhoneBook);
			else if (buf == "EXIT")
				break ;
			else
			{
				std::cerr << "Invalid prompt!" << std::endl;
				std::cout << "----------------------------" << std::endl;
			}
		}
	}
	return (0);
}
