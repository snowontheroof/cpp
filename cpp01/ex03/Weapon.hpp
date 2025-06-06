/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:34:34 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 10:34:35 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon {
	private:
		std::string	type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		const std::string&	getType() const;
		void				setType(std::string type);
};

#endif
