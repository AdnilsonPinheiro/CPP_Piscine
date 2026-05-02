#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const std::string& _type) : Animal(_type)
{
	this->type = "Cat";
	this->brain = new Brain(_type);
	std::cout << "Cat param constructor" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	this->brain = new Brain(*rhs.brain);
	std::cout << "Cat copy constructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs){
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	std::cout << "Cat assignment operator" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor" << std::endl;
}

void	Cat::makeSound()const
{
	std::cout << "meow" << std::endl;
}

Brain*	Cat::getBrain()const
{
	return (this->brain);
}

void	Cat::setType(const std::string& _type)
{
	this->type = _type;
}