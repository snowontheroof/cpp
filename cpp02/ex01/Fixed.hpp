/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:36:05 by sojala            #+#    #+#             */
/*   Updated: 2025/07/11 15:43:57 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_RawBits;
		static const int	_FractBits;

	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed (const Fixed& obj);
		Fixed &operator=(const Fixed& f);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
