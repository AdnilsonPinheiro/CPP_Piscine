#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	HitPoints;
	unsigned int	EnergyPoints;
	unsigned int	AttackDamage;
public:
	ClapTrap	();
	ClapTrap	(std::string name);
	ClapTrap	(const ClapTrap& src);
	ClapTrap&	operator=(const ClapTrap& src);
	~ClapTrap	();

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif