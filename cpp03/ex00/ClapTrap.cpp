#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : AttackDamage(0), HitPoints(10), EnergyPoints(10)
{
	std::cout << "Default constructor called." << std::endl;
	name = "Nameless ClapTrap";
}

ClapTrap::ClapTrap(std::string name) : AttackDamage(0), HitPoints(10), EnergyPoints(10)
{
	std::cout << "Parameterized constructor called." << std::endl;
	name = name;
}

ClapTrap::ClapTrap(const ClapTrap& src) : AttackDamage(0)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &src)
		ClapTrap(src);
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl;
}