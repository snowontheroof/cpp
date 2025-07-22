/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:05:08 by sojala            #+#    #+#             */
/*   Updated: 2025/07/22 10:47:36 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& other);
		~Cat();

		void	makeSound() const override;
};

#endif
