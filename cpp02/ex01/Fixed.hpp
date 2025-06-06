/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:36:05 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 17:42:01 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					_RawBits;
		static const int	_FractBits;

	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed (const Fixed& obj);
		Fixed &operator=(const Fixed& f);
		//copy assignment operator overload
		~Fixed();
};

#endif
