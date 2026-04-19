#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
	ClapTrap("Default_clap_name"),
	name("Default")
{
	this->HitPoints = FragTrap::default_HitPoints;
	this->EnergyPoints = ScavTrap::default_EnergyPoints;
	this->AttackDamage = FragTrap::default_AttackDamage;
	std::cout << "DiamondTrap default constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& newName) : 
	ClapTrap(newName + "_clap_name"),
	name(newName)
{
	this->HitPoints = FragTrap::default_HitPoints;
	this->EnergyPoints = ScavTrap::default_EnergyPoints;
	this->AttackDamage = FragTrap::default_AttackDamage;
	std::cout << "DiamondTrap parameterized constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : 
	ClapTrap(src),
	ScavTrap(src),
	FragTrap(src)
{
	this->name = src.name;
	this->HitPoints = src.HitPoints;
	this->EnergyPoints = src.EnergyPoints;
	this->AttackDamage = src.AttackDamage;
	std::cout << "DiamondTrap copy constructor called for " << this->name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << "DiamondTrap assignment operator called for " << this->name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My ClapTrap name is " << ClapTrap::name << std::endl;
	std::cout << "But my real personal name is " << this->name << std::endl;
}