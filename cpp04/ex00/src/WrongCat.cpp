#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const std::string& _type) : WrongAnimal(_type)
{
	std::cout << "WrongCat param constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat assignment operator" << std::endl;
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void	WrongCat::makeSound()const
{
	std::cout << "WRONG meow" << std::endl;
}