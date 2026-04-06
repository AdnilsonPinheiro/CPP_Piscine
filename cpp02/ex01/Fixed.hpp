#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		Fixed	();
		Fixed	(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed	();

		Fixed	(const int value);
		Fixed	(const float value);

		void	setRawBits(const int raw);
		int		getRawBits()const;

		float	toFloat()const;
		int		toInt()const;
};

#endif