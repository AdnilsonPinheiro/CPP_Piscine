#include "./Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other){
		this->fixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called." << std::endl;
	this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called." << std::endl;
	this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->fixedPointValue = raw;
}

int		Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called." << std::endl;
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

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}