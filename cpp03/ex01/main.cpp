#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	a;
	ScavTrap	b(a);
	ScavTrap	c("Hugo Scavez");

	a.attack("someone");
	a = c;
	a.attack("someone");
	b.attack("someone");
	c.attack("someone");
	c.guardGate();

	return 0;
}