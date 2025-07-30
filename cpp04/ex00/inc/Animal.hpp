/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:04 by sojala            #+#    #+#             */
/*   Updated: 2025/07/30 15:35:58 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class	Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal& obj);
		Animal&	operator=(const Animal& other);
		virtual	~Animal();

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif
