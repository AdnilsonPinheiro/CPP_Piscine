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
	return (static_cast<float>(fixedPointValue) / (1 << fractionalBits));
}

int		Fixed::toInt()const
{
	return ()
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}