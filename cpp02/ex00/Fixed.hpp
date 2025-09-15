#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractBits;

	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
