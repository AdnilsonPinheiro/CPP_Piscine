#include "../includes/FragTrap.hpp"

unsigned int const	FragTrap::default_HitPoints = 100;
unsigned int const	FragTrap::default_EnergyPoints = 100;
unsigned int const	FragTrap::default_AttackDamage = 30;

FragTrap::FragTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "Default constructor called for FragTrap " << this->name << std::endl;
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{	
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "Parameterized constructor called for FragTrap " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "Copy constructor called for FragTrap " << this->name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	std::cout << "Assignment operator called assigning to FragTrap " << this->name << " from FragTrap " << src.name << std::endl;
	if (this != &src)
		ClapTrap::operator=(src);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for FragTrap " << this->name << std::endl;
}

//Prints UTF-8 raised hand emoji
void	FragTrap::highFivesGuys()
{
	std::cout << this->name << " requesting positive high-fives " << "\xE2\x9C\x8B" << std::endl;
}