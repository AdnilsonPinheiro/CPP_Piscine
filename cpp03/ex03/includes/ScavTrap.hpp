#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap	();
	ScavTrap	(std::string const& name);
	ScavTrap	(const ScavTrap& src);
	ScavTrap&	operator=(const ScavTrap& src);
	~ScavTrap	();

	void	guardGate();
	void	attack(const std::string& target);

	static unsigned int const	default_HitPoints;
	static unsigned int const	default_EnergyPoints;
	static unsigned int const	default_AtackDamage;
};

#endif