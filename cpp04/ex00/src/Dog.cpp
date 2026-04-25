#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const std::string& _type) : Animal(_type)
{
	std::cout << "Dog param constructor" << std::endl;
}

Dog::Dog(const Dog& rhs)
{
	std::cout << "Dog reference constructor" << std::endl;
	this->type = rhs.getType();
}

Dog&	Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog assignment operator" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void	Dog::setType(const std::string& _type)
{
	this->type = _type;
}

const std::string&	Dog::getType()const
{
	return (this->type);
}

void	Dog::makeSound()
{
	std::cout << "woof" << std::endl;
}