#include "./Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called." << std::endl;
	this->fixed_point = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other){
		this->fixed_point = other.getRawBits();
	}
	return (*this);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->fixed_point = raw;
}

int		Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->fixed_point);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}