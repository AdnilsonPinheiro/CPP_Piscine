#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const std::string& _type) : Animal(_type)
{
	std::cout << "Cat param constructor" << std::endl;
	this->brain = new Brain(_type);
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->brain = new Brain(*rhs.brain);
}

Cat&	Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat assignment operator" << std::endl;
	if (this != &rhs){
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete this->brain;
}

void	Cat::makeSound()const
{
	std::cout << "meow" << std::endl;
}

Brain*	Cat::getBrain()const
{
	return (this->brain);
}