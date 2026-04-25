#include "./includes/DiamondTrap.hpp"

int	main()
{
	DiamondTrap	A;
	DiamondTrap	B("B");
	DiamondTrap	C(A);

	A = B;
	A.attack("target");
	A.highFivesGuys();
	A.whoAmI();
	A.takeDamage(5);
	A.beRepaired(2);
	A.guardGate();

	return 0;
}