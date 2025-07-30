#ifndef WRONGAnimal_HPP
# define WRONGAnimal_HPP
# include <iostream>

class	WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal&	operator=(const WrongAnimal& other);
		virtual	~WrongAnimal();

		std::string		getType() const;
		void			makeSound() const;
};

#endif
