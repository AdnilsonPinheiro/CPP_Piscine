#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const std::string& _type) : Animal(_type)
{
	std::cout << "Cat param constructor" << std::endl;
}

Cat::Cat(const Cat& rhs)
{
	std::cout << "Cat reference constructor" << std::endl;
	this->type = rhs.getType();
}

Cat&	Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat assignment operator" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void	Cat::setType(const std::string& _type)
{
	this->type = _type;
}

const std::string&	Cat::getType()const
{
	return (this->type);
}

void	Cat::makeSound()
{
	std::cout << "meow" << std::endl;
}