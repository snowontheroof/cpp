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

		void			setIdea(int index, std::string input);
		std::string&	getIdea(int index) const;
		void			makeSound() const override;
};

#endif
