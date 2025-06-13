/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:36:05 by sojala            #+#    #+#             */
/*   Updated: 2025/06/13 18:07:04 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int		_RawBits;
		static const int	_FractBits;

	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed (const Fixed& obj);
		Fixed &operator=(const Fixed& f);
		~Fixed();

		static int&			min(int& fixedP1, int& fixedP2);
		static const int&	min(const int& fixedP1, const int& fixedP2);
		static int&			max(int& fixedP1, int& fixedP2);
		static const int&	max(const int& fixedP1, const int& fixedP2);

		// int		operator+(int& fixedP);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
