/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:04 by sojala            #+#    #+#             */
/*   Updated: 2025/07/22 10:47:31 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& obj);
		Animal&	operator=(const Animal& other);
		virtual	~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif
