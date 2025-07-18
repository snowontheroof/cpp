#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& other);
		~Cat();

		void	makeSound() const override;
};

#endif
