/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:33:41 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 10:42:05 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string	name;

		public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce(void);
		void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
