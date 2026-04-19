#include "../includes/ScavTrap.hpp"

unsigned int const	ScavTrap::default_HitPoints = 100;
unsigned int const	ScavTrap::default_EnergyPoints = 50;
unsigned int const	ScavTrap::default_AtackDamage = 20;

ScavTrap::ScavTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "Default constructor called for ScavTrap " << this->name << std::endl;
}

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name)
{
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "Parameterized constructor called for ScavTrap " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called copying from " << src.name << " to " << this->name << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "Assignment operator called assigning to ScavTrap " << this->name << " from ScavTrap " << src.name << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->HitPoints = src.HitPoints;
		this->EnergyPoints = src.EnergyPoints;
		this->AttackDamage = src.AttackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap " << this->name << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode. You shall not pass!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0){
		std::cout << "ScavTrap " << this->name << " attacks " << target << " , causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints--;
		std::cout << "\tBut it spends 1 Energy Point. It now has " << this->EnergyPoints << " Energy Points." << std::endl;
	}
	else if (this->EnergyPoints < 1) {
		std::cout << "ScavTrap " << this->name << " has no Energy Points left. It can't do anything anymore..." << std::endl;
	}
	else if (this->HitPoints < 1) {
		std::cout << "ScavTrap " << this->name << " has taken too much damage. It can't do anything anymore..." << std::endl;
	}
}