#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a;
	ClapTrap	b("Nuno");
	int			i;

	for (i = 0; i < 11; i++){
		a.attack("Um Vacilao na Rua");
	}

	for (i = 0; i < 4; i++){
		b.takeDamage(2);
	}

	for (i = 0; i < 2; i++){
		b.beRepaired(1);
	}

	return 0;
}