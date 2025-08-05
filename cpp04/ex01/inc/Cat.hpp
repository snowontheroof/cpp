/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:41:02 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:41:03 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	_myBrain;

	public:
		Cat();
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& other);
		~Cat();

		Brain*	getBrain() const;
		void	makeSound() const override;
};

#endif
