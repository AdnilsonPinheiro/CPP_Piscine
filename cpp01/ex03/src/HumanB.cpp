#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string newName) : name(newName), weapon(NULL) {}

void	HumanB::attack(void)const {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " is has no weapon and attacks with their bare hands. It is not very effective." << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon){
	weapon = &newWeapon;
}

HumanB::~HumanB(void) {}
