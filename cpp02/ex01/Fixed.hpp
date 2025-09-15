#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractBits;

	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed (const Fixed& obj);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
