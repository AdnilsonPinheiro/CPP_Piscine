#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WRonG DefAult ConstRUctoR" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& _type) : type(_type)
{
	std::cout << "WRonG PAram ConstRUctoR" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) : type(rhs.type)
{
	std::cout << "WRonG cOPy ConstRUctoR" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WRonG ASSingMent opERAtoR" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WRonG DEStrucTor" << std::endl;
}

void	WrongAnimal::setType(const std::string& _type)
{
	this->type = _type;
}

const std::string&	WrongAnimal::getType()const
{
	return (this->type);
}

void	WrongAnimal::makeSound()const
{
	std::cout << "*weird cosmic horror sounds*" << std::endl;
}