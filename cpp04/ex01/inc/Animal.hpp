/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:40:54 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:59:38 by sonjaojala       ###   ########.fr       */
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

		const std::string&	getType() const;
		virtual void		makeSound() const;
};

#endif
