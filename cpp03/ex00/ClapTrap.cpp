#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name ("Nameless"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Parameterized constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &src){
		this->name = src.name;
		this->HitPoints = src.HitPoints;
		this->EnergyPoints = src.EnergyPoints;
		this->AttackDamage = src.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0){
		std::cout << "ClapTrap " << this->name << " attacks " << target << " , causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints--;
		std::cout << "\tBut it spends 1 Energy Point. It now has " << this->EnergyPoints << " Energy Points." << std::endl;
	}
	else if (this->EnergyPoints < 1) {
		std::cout << "ClapTrap " << this->name << " has no Energy Points left. It can't do anything anymore..." << std::endl;
	}
	else if (this->HitPoints < 1) {
		std::cout << "ClapTrap " << this->name << " has taken too much damage. It can't do anything anymore..." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints < 1){
		std::cout << "ClapTrap " << this->name << " is already pretty beaten, give it a break." << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name << " takes " << amount << " of damage." << std::endl;
		this->HitPoints -= amount;
		std::cout << "\tClapTrap " << this->name << " now has " << this->HitPoints << " Hit Points." << std::endl;
		if (this->HitPoints < 1){
			std::cout << "\tClapTrap " << this->name << " has taken too much damage. It is useless now." << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoints < 1){
		std::cout << "ClapTrap " << this->name << " has taken too much damage. It can't do anything anymore." << std::endl;
	}
	else if (this->EnergyPoints < 1){
		std::cout << "ClapTrap " << this->name << " has no energy left. It can't do anything anymore." << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name << " repaired itself " << amount << " Hit Points!" << std::endl;
		this->EnergyPoints--;
		std::cout << "\tIn doing so, ClapTrap " << this->name << " has spent 1 Energy Point. It now has " << this->EnergyPoints << " Energy Points." << std::endl;
		this->HitPoints += amount;
		std::cout << "\tClapTrap " << this->name << " now regained " << amount << " Hit Points! It now has " << this->HitPoints << " Hit Points!" << std::endl;
	}
}
