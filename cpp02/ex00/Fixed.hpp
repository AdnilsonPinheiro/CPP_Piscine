#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed{
	private:
		int					fixed_point;
		static const int	frac_bits = 8;

	public:
		Fixed();
		Fixed	(const Fixed& other);
		Fixed&	operator=(const Fixed& other);

		void	setRawBits(const int raw);

		int		getRawBits()const;

		~Fixed();
};

#endif