#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP
# include <iostream>

class	A_Animal
{
	protected:
		std::string	type;

	public:
		A_Animal();
		A_Animal(const A_Animal& obj);
		A_Animal&	operator=(const A_Animal& other);
		virtual	~A_Animal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;
};

#endif
