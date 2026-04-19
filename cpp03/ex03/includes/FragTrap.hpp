#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap	();
	FragTrap	(std::string const& name);
	FragTrap	(const FragTrap& src);
	FragTrap&	operator=(const FragTrap& src);
	~FragTrap	();

	void	highFivesGuys();

	static unsigned int const	default_HitPoints;
	static unsigned int const	default_EnergyPoints;
	static unsigned int const	default_AttackDamage;
};

#endif