#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap	();
	ScavTrap	(std::string const& name);
	ScavTrap	(const ScavTrap& src);
	ScavTrap&	operator=(const ScavTrap& src);
	~ScavTrap	();

	void	guardGate();
	void	attack(const std::string& target);
};

#endif