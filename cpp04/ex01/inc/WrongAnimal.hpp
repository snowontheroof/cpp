#ifndef WRONGAnimal_HPP
# define WRONGAnimal_HPP
# include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal&	operator=(const WrongAnimal& other);
		virtual	~WrongAnimal();

		void			makeSound() const;
		std::string		getType() const;
};

#endif
