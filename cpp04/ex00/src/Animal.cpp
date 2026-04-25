#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const std::string& _type) : type(_type)
{
	std::cout << "Animal param constructor" << std::endl;
}

Animal::Animal(const Animal& rhs) : type(rhs.type)
{
	std::cout << "Animal copy constructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal assignment operator" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

void	Animal::setType(const std::string& _type)
{
	this->type = _type;
}

const std::string&	Animal::getType()const
{
	return (this->type);
}

void	Animal::makeSound()const
{
	return;
}