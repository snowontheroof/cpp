/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:41:58 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:41:59 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
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
