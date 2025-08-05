/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:41:53 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 15:03:50 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class	AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(const AAnimal& obj);
		AAnimal&	operator=(const AAnimal& other);
		virtual	~AAnimal();

		const std::string&	getType() const;
		virtual void		makeSound() const = 0;
};

#endif
