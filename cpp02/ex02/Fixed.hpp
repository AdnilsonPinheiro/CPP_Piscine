#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		//Canonical Form
		Fixed	();
		Fixed	(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed	();

		//Other constructors
		Fixed	(const int value);
		Fixed	(const float value);

		//Setters and Getters
		void	setRawBits(const int raw);
		int		getRawBits()const;

		//Conversion methods
		float	toFloat()const;
		int		toInt()const;

		//Comparison operators
		bool	operator>(const Fixed& rhs)const;
		bool	operator<(const Fixed& rhs)const;
		bool	operator>=(const Fixed& rhs)const;
		bool	operator<=(const Fixed& rhs)const;
		bool	operator==(const Fixed& rhs)const;
		bool	operator!=(const Fixed& rhs)const;

		//Arithmetic operators
		Fixed	operator+(const Fixed& rhs)const;
		Fixed	operator-(const Fixed& rhs)const;
		Fixed	operator*(const Fixed& rhs)const;
		Fixed	operator/(const Fixed& rhs)const;

		//Prefix increment and decrement
		Fixed&	operator++();
		Fixed&	operator--();

		//Postfix increment and decrement
		Fixed	operator++(int);
		Fixed	operator--(int);

		//Overloaded functions
		static Fixed&		min(Fixed& lhs, Fixed &rhs);
		static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
		static Fixed&		max(Fixed& lhs, Fixed& rhs);
		static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);
};

// << operator overload
std::ostream&	operator<<(std::ostream& out, const Fixed& obj);

#endif