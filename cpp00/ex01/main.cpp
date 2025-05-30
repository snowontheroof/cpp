#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	add_contact_info(std::string msg, std::string& field)
{
	std::cout << msg;
	if (!std::getline(std::cin, field))
	{
		std::cout << "\nExiting phonebook" << std::endl;
		exit(0);
	}
	if (field == "")
		std::cerr << "You must type something to each field!" << std::endl;
	return (field);
}

void	add_contact(PhoneBook& MyPhoneBook, int& i)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	if (i == 8)
		i = 0;
	std::cout << "Let's add a new contact! Please give me some info:" << std::endl;
	if (add_contact_info("First name: ", first_name) == "")
		return ;
	if (add_contact_info("Last name: ", last_name) == "")
		return ;
	if (add_contact_info("Nickname: ", nickname) == "")
		return ;
	if (add_contact_info("Phone number: ", phone_number) == "")
		return ;
	if (add_contact_info("Darkest secret: ", darkest_secret) == "")
		return ;
	MyPhoneBook.add_contact_to_phonebook(MyPhoneBook, i, first_name, last_name, nickname,
		phone_number, darkest_secret);
	i++;
	return ;
}

int	main(int argc, char **argv)
{
	std::string buf;
	PhoneBook MyPhoneBook;
	int	i = 0;

	(void)argv;
	if (argc != 1)
		std::cerr << "No arguments accepted at this point!" << std::endl;
	else
	{
		while (1)
		{
			std::cout << "What should we do? ADD, SEARCH or EXIT?" << std::endl;
			if (!std::getline(std::cin, buf))
			{
				std::cout << "Exiting phonebook" << std::endl;
				break ;
			}
			if (buf == "ADD")
				add_contact(MyPhoneBook, i);
			else if (buf == "SEARCH")
				MyPhoneBook.search_contact(MyPhoneBook);
			else if (buf == "EXIT")
				break ;
			else
				std::cerr << "Invalid prompt!" << std::endl;
		}
	}
	return 0;
}
