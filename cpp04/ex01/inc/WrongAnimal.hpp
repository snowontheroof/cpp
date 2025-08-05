/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:41:09 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:59:48 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class	WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal&	operator=(const WrongAnimal& other);
		virtual	~WrongAnimal();

		const std::string&	getType() const;
		void				makeSound() const;
};

#endif
