#include "includes/Weapon.hpp"
#include "includes/HumanA.hpp"
#include "includes/HumanB.hpp"

int	main(void){
	Weapon	club = Weapon("crude spiked club");

	HumanA	bob("Bob", club);
	HumanB	jim("Jim");
	bob.attack();
	jim.attack();
	club.setType("Some other weapon");
	jim.setWeapon(club);
	bob.attack();
	jim.attack();

	return 0;
}