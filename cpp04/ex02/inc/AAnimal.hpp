#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class	AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(const AAnimal& obj);
		AAnimal&	operator=(const AAnimal& other);
		virtual	~AAnimal();

		const std::string&	getType() const;
		virtual void		makeSound() const = 0;
};

#endif
