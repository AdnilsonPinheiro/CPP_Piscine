#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a;
	ClapTrap	c("THE BEST");
	ClapTrap	d;

	for (int i = 11; i > 0; i--){
		a.attack("a target");
	}

	ClapTrap	b(a);

	std::cout << std::endl;

	for (int i = 11; i > 0; i--){
		b.attack("SOMEONE");
	}

	std::cout << std::endl;

	for (int i = 11; i > 0; i--){
		c.attack("ANOTHER fascist");
	}

	std::cout << std::endl;

	d = c;

	std::cout << std::endl;

	for (int i = 11; i > 0; i--){
		d.attack("THE SAME fascist");
	}

	std::cout << std::endl;

	return 0;
}