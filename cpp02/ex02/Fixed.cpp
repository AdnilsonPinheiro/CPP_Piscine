#include "./Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called." << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other){
		this->fixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called." << std::endl;
	this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called." << std::endl;
	this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

void	Fixed::setRawBits(const int raw)
{
	//std::cout << "setRawBits member function called." << std::endl;
	this->fixedPointValue = raw;
}

int		Fixed::getRawBits()const
{
	//std::cout << "getRawBits member function called." << std::endl;
	return (this->fixedPointValue);
}

float	Fixed::toFloat()const
{
	return (static_cast<float>(this->fixedPointValue) / (1 << fractionalBits));
}

int		Fixed::toInt()const
{
	return (roundf(this->fixedPointValue >> fractionalBits));
}

bool	Fixed::operator>(const Fixed& rhs)const
{
	return (this->fixedPointValue > rhs.fixedPointValue);
}

bool	Fixed::operator<(const Fixed& rhs)const
{
	return (this->fixedPointValue < rhs.fixedPointValue);
}

bool	Fixed::operator>=(const Fixed& rhs)const
{
	return (this->fixedPointValue >= rhs.fixedPointValue);
}

bool	Fixed::operator<=(const Fixed& rhs)const
{
	return (this->fixedPointValue <= rhs.fixedPointValue);
}

bool	Fixed::operator==(const Fixed& rhs)const
{
	return (this->fixedPointValue == rhs.fixedPointValue);
}

bool	Fixed::operator!=(const Fixed& rhs)const
{
	return (this->fixedPointValue != rhs.fixedPointValue);
}

Fixed	Fixed::operator+(const Fixed& rhs)const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed& rhs)const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed& rhs)const
{
	Fixed	result;
	result.setRawBits(static_cast<long>(this->getRawBits() * rhs.getRawBits()) >> fractionalBits);
	return result;	
}

Fixed	Fixed::operator/(const Fixed& rhs)const
{
	Fixed	result;
	result.setRawBits(static_cast<long>(this->getRawBits() << fractionalBits) / rhs.getRawBits());
	return result;
}

Fixed&	Fixed::operator++()
{
	fixedPointValue++;
	return *this;
}

Fixed&	Fixed::operator--()
{
	fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;
	operator++();
	return old;
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;
	operator--();
	return old;
}

Fixed&		Fixed::min(Fixed& lhs, Fixed &rhs)
{
	return ((lhs < rhs) ? lhs : rhs);
}

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	return ((lhs < rhs) ? lhs : rhs);
}

Fixed&		Fixed::max(Fixed& lhs, Fixed& rhs)
{
	return ((lhs > rhs) ? lhs : rhs);
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	return ((lhs > rhs) ? lhs : rhs);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}
