/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:41:06 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:41:07 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
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
