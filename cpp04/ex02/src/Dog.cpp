#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	this->brain = new Brain;
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const std::string& _type) : Animal(_type)
{
	this->brain = new Brain(_type);
	std::cout << "Dog param constructor" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	this->brain = new Brain(*rhs.brain);
	std::cout << "Dog copy constructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs){
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	std::cout << "Dog assignment operator" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor" << std::endl;
}

void	Dog::makeSound()const
{
	std::cout << "woof" << std::endl;
}

Brain*	Dog::getBrain()const
{
	return (this->brain);
}

void	Dog::setType(const std::string& _type)
{
	this->type = _type;
}