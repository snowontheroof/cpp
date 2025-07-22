/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:11 by sojala            #+#    #+#             */
/*   Updated: 2025/07/22 10:47:42 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& obj);
		Dog&	operator=(const Dog& other);
		~Dog();

		void	makeSound() const override;
};

#endif
