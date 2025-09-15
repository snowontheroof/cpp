#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
{
	private:
		Brain*	_myBrain;

	public:
		Dog();
		Dog(const Dog& obj);
		Dog&	operator=(const Dog& other);
		~Dog();

		Brain*	getBrain() const;
		void	makeSound() const override;
};

#endif
