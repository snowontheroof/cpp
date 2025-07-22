/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:15 by sojala            #+#    #+#             */
/*   Updated: 2025/07/22 10:05:16 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAnimal_HPP
# define WRONGAnimal_HPP
# include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal&	operator=(const WrongAnimal& other);
		virtual	~WrongAnimal();

		void			makeSound() const;
		std::string		getType() const;
};

#endif
