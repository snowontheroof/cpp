#ifndef CAT_HPP
# define CAT_HPP
# include "A_Animal.hpp"
# include "Brain.hpp"

class	Cat : public A_Animal
{
	private:
		Brain*	ideas;

	public:
		Cat();
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& other);
		~Cat();

		Brain*	getBrain() const;
		void	makeSound() const override;
};

#endif
