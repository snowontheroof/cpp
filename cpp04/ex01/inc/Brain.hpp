#ifndef BRAIN_HPP
# define BRAIN_HPP
# include "Brain.hpp"
# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain& obj);
		Brain&	operator=(const Brain& other);
		~Brain();

		void				setIdea(int index, const std::string& newIdea);
		const std::string&	getIdea(int index) const;
};

#endif
