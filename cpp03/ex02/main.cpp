#include <iostream>
#include "./includes/FragTrap.hpp"

int	main()
{
	FragTrap	a;
	FragTrap	b(a);
	FragTrap	c("Fragrant");

	a = c;

	a.attack("you");
	a.highFivesGuys();

	return 0;
}