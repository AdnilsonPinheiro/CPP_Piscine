#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : AttackDamage(0), HitPoints(10), EnergyPoints(10)
{
	std::cout << "Default constructor called." << std::endl;
	name = "This ClapTrap has no name";
}

ClapTrap::ClapTrap(std::string name) : AttackDamage(0), HitPoints(10), EnergyPoints(10)
{
	std::cout << "Parameterized constructor called." << std::endl;
	name = name;
}

