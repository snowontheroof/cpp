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

		void			setIdea(int index, std::string);
		std::string&	getIdea(int index) const;
		void			makeSound() const override;
};

#endif
