#ifndef DOG_HPP
# define DOG_HPP
# include "A_Animal.hpp"
# include "Brain.hpp"

class	Dog : public A_Animal
{
	private:
		Brain*	ideas;

	public:
		Dog();
		Dog(const Dog& obj);
		Dog&	operator=(const Dog& other);
		~Dog();

		Brain*	getBrain() const;
		void	makeSound() const override;
};

#endif
