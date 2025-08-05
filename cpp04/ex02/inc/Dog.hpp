/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:42:05 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:42:06 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
