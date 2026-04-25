#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const std::string& _type) : Animal(_type)
{
	std::cout << "Dog param constructor" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	std::cout << "Dog copy constructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog assignment operator" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void	Dog::makeSound()const
{
	std::cout << "woof" << std::endl;
}