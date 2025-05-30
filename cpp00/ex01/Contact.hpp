#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;
		bool		_IsSet;

	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname,
			std::string phone_number, std::string darkest_secret, bool is_set);
		~Contact();

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
		bool		getIsSet() const;
};

#endif
